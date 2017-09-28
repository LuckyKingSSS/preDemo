
#include "GlobalResources_p.h"



#include "Interface/INLEFactory.h"
#include "inc_CommonLib/WSCreateInstance.h"




//////////////////////////////////////////////////////////////////////////

#define MAKE_TAG(ch1, ch2, ch3, ch4) (\
	(((quint32)(ch4)) << 24) | \
	(((quint32)(ch3)) << 16) | \
	(((quint32)(ch2)) << 8) | \
	((quint32)(ch1)) \
	)

static inline quint16 getUShort(const unsigned char *p)
{
	quint16 val;
	val = *p++ << 8;
	val |= *p;

	return val;
}

static QString getEnglishName(const uchar *table, quint32 bytes)
{
	QString i18n_name;

#ifdef _WIN32
	enum {
		NameRecordSize = 12,
		FamilyId = 1,
		MS_LangIdEnglish = 0x009
	};

	// get the name table
	quint16 count;
	quint16 string_offset;
	const unsigned char *names;

	int microsoft_id = -1;
	int apple_id = -1;
	int unicode_id = -1;

	if (getUShort(table) != 0)
		goto error;

	count = getUShort(table + 2);
	string_offset = getUShort(table + 4);
	names = table + 6;

	if (string_offset >= bytes || 6 + count*NameRecordSize > string_offset)
		goto error;

	for (int i = 0; i < count; ++i) {
		// search for the correct name entry

		quint16 platform_id = getUShort(names + i*NameRecordSize);
		quint16 encoding_id = getUShort(names + 2 + i*NameRecordSize);
		quint16 language_id = getUShort(names + 4 + i*NameRecordSize);
		quint16 name_id = getUShort(names + 6 + i*NameRecordSize);

		if (name_id != FamilyId)
			continue;

		enum {
			PlatformId_Unicode = 0,
			PlatformId_Apple = 1,
			PlatformId_Microsoft = 3
		};

		quint16 length = getUShort(names + 8 + i*NameRecordSize);
		quint16 offset = getUShort(names + 10 + i*NameRecordSize);
		if (DWORD(string_offset + offset + length) >= bytes)
			continue;

		if ((platform_id == PlatformId_Microsoft
			&& (encoding_id == 0 || encoding_id == 1))
			&& (language_id & 0x3ff) == MS_LangIdEnglish
			&& microsoft_id == -1)
			microsoft_id = i;
		// not sure if encoding id 4 for Unicode is utf16 or ucs4...
		else if (platform_id == PlatformId_Unicode && encoding_id < 4 && unicode_id == -1)
			unicode_id = i;
		else if (platform_id == PlatformId_Apple && encoding_id == 0 && language_id == 0)
			apple_id = i;
	}
	{
		bool unicode = false;
		int id = -1;
		if (microsoft_id != -1) {
			id = microsoft_id;
			unicode = true;
		}
		else if (apple_id != -1) {
			id = apple_id;
			unicode = false;
		}
		else if (unicode_id != -1) {
			id = unicode_id;
			unicode = true;
		}
		if (id != -1) {
			quint16 length = getUShort(names + 8 + id*NameRecordSize);
			quint16 offset = getUShort(names + 10 + id*NameRecordSize);
			if (unicode) {
				// utf16

				length /= 2;
				i18n_name.resize(length);
				QChar *uc = (QChar *)i18n_name.unicode();
				const unsigned char *string = table + string_offset + offset;
				for (int i = 0; i < length; ++i)
					uc[i] = getUShort(string + 2 * i);
			}
			else {
				// Apple Roman

				i18n_name.resize(length);
				QChar *uc = (QChar *)i18n_name.unicode();
				const unsigned char *string = table + string_offset + offset;
				for (int i = 0; i < length; ++i)
					uc[i] = QLatin1Char(string[i]);
			}
		}
	}
error:
	//qDebug("got i18n name of '%s' for font '%s'", i18n_name.latin1(), familyName.toLocal8Bit().data());

#endif // _WIN32

	return i18n_name;
}

static QString getEnglishName(const QString &familyName)
{
	QString i18n_name;

#ifdef _WIN32
	HDC hdc = GetDC(0);
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	memcpy(lf.lfFaceName, familyName.utf16(), qMin(LF_FACESIZE, familyName.length()) * sizeof(wchar_t));
	lf.lfCharSet = DEFAULT_CHARSET;
	HFONT hfont = CreateFontIndirect(&lf);

	if (!hfont) {
		ReleaseDC(0, hdc);
		return QString();
	}

	HGDIOBJ oldobj = SelectObject(hdc, hfont);

	const DWORD name_tag = MAKE_TAG('n', 'a', 'm', 'e');

	// get the name table
	unsigned char *table = 0;

	DWORD bytes = GetFontData(hdc, name_tag, 0, 0, 0);
	if (bytes == GDI_ERROR) {
		// ### Unused variable
		/* int err = GetLastError(); */
		goto error;
	}

	table = new unsigned char[bytes];
	GetFontData(hdc, name_tag, 0, table, bytes);
	if (bytes == GDI_ERROR)
		goto error;

	i18n_name = getEnglishName(table, bytes);
error:
	delete[] table;
	SelectObject(hdc, oldobj);
	DeleteObject(hfont);
	ReleaseDC(0, hdc);

	//qDebug("got i18n name of '%s' for font '%s'", i18n_name.latin1(), familyName.toLocal8Bit().data());
#endif _WIN32
	return i18n_name;
}

//////////////////////////////////////////////////////////////////////////
static ICaptionEnvironment *sCaptionEnvironment = nullptr;
ICaptionEnvironment* ICaptionEnvironment::GetInstance()
{
	if (sCaptionEnvironment == nullptr)
	{
		sCaptionEnvironment = new CaptionEnvironment();
	}
	return sCaptionEnvironment;
}

void CaptionEnvironment::Release()
{
	if (sCaptionEnvironment)
	{
		delete sCaptionEnvironment;
		sCaptionEnvironment = nullptr;
	}
}

INLEFactory* CaptionEnvironment::GetNLEFactory()
{
	return m_pFactory;
}

CaptionEnvironment::CaptionFonts CaptionEnvironment::GetNLEFonts()
{
	return m_fonts;
}


CaptionEnvironment::CaptionEnvironment()
{
	WSCreateInstance::Instance()->wsCreateInstance(CLSID_NLEFactory, nullptr, 0, IID_INLEFactory, (void**)&m_pFactory);
    
    
	m_pFactory->Init(NULL);

	m_pFontLibrary = m_pFactory->CreateFontLibrary();
	Q_ASSERT(m_pFontLibrary);
	InitSystemFont();
}
void CaptionEnvironment::InitSystemFont()
{
	QStringList englishFamilyNames;
	QFontDatabase database;
	foreach(const QString &family, database.families())
	{
		QString englishname = getEnglishName(family);
		englishFamilyNames.append(englishname);
	}

	int nCount = m_pFontLibrary->GetFontCount();
	wchar_t wszName[MAX_PATH];
	QStringList familyNames;
	for (int i = 0; i < nCount; i++)
	{
		m_pFontLibrary->GetFontName(i, wszName);
		QString str1 = QString::fromWCharArray(wszName);

		int nIdx = englishFamilyNames.indexOf(str1);

		if (nIdx >= 0)
			familyNames.append(database.families().at(nIdx));
		else
			familyNames.append(str1);
	}
	familyNames.sort();

	for (int i = 0; i < familyNames.size(); i++)
	{
		QString str2 = familyNames[i];
		int nFindIdx = database.families().indexOf(str2);
		if (nFindIdx >= 0)
			str2 = englishFamilyNames[nFindIdx];

		m_fonts.push_back(std::make_tuple(familyNames[i], str2));
	}
}
