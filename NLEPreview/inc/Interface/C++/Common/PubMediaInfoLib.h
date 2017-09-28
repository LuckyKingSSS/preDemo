#pragma once
enum SCAN_TYPE {
	SCAN_TYPE_PROGRESSIVE, ///< ����ģʽ
	SCAN_TYPE_INTERLACED, ///< ��֯ģʽ
	SCAN_TYPE_UNKNOWN,	///< ģʽδ֪
	SCAN_TYPE_RESERVED	///< �����ֶ�
};
enum ENCRYPTION_TYPE {
	ENCRYPTION_TYPE_ENCRYPTION,///< ��Ƶ�ļ�����
	ENCRYPTION_TYPE_UNENCRYPTION, ///< ��Ƶ�ļ�û�м���		
};

#ifndef WIN32
#define  __stdcall 
#endif

struct MEDIA_INFO_LIB_ID3_INFO
{
	wchar_t szArtist[260];      // ������
	wchar_t szTitle[260];       // ����       
	wchar_t szTrackNumber[260]; // �����
	wchar_t szAlbum[260];     	// ר��    
	wchar_t szDate[260];    	//���   
	wchar_t szGenre[260];	    // ���  
	wchar_t szPublisher[260];   //������
};

struct Video_QuickTime_Mov_Sprite
{
	int  widthscale_a ;
	int  widthrotate_b ;
	int widthangle_u  ;
	int heightscale_c ;
	int heightrotate_d ;
	int	heightangle_v ;
	int positionleft_x ;
	int positiontop_y ;
	int divider_w ;

	int  nRotate;
};
struct MEDIA_INFO_LIB_VIDEO_INFO
{
	int		nVideoID;		// �ӹ��	��	�ļ��б��
	int		nVideoDuration;	//					ms

	wchar_t	wcsFourCC[260];	// ��Ƶ������ 
	int		nWidth;			// �ֱ��ʿ��		pixel
	int		nHeight;		// �ֱ��ʸ߶�
	double  dFrameRate;		// ֡��
	int		nTotalFrames;   // ֡�� 
	int		nBitrate;		// ����				bps
	wchar_t wcsCodeInfo[260];//������������Ϣ

	SCAN_TYPE	scanType;	//ɨ������
	ENCRYPTION_TYPE encryType;	//����
	
	int xratio;	// x������� 	
	int yratio;	// y�������

	double dMaxFrameRate;
	int	   nIsVBR;
	Video_QuickTime_Mov_Sprite vqmSprite;

	
};

struct MEDIA_INFO_LIB_AUDIO_INFO
{
	int		nAudioID;			// ����� �� �ļ��б��
	int		nAudioDuration;		//				ms

	wchar_t	wcsFourCC[260];	// ��Ƶ������
	int		nSampleRate;	// ������			Hz
	int		nChannels;		// ��������
	int		nBitrate;		// ����				bps 
	wchar_t wcsCodeInfo[260];//������������Ϣ

	ENCRYPTION_TYPE audioEncryType;	//����
};

struct MEDIA_INFO_PROGRAM_INFO
{
	int		nProgramID;		   // Ĭ��0
	int		nProgramDuration;  //ms
	
	ENCRYPTION_TYPE programEncryType;	//����

	MEDIA_INFO_LIB_AUDIO_INFO  mAudioProgrm;
	MEDIA_INFO_LIB_VIDEO_INFO  mpVideoProgrm;
};
struct  MEDIA_INFO_LIB_FILE_INFO
{
	wchar_t szDate[260];           
	wchar_t	wcsFileFormat[260];		//�ļ���ʽ
	wchar_t wcsFileFormatInfo[260];	//�ļ�������Ϣ
	double dFileSize;				//�ļ���С			byte
	int	nDuration;					//�ļ�����ʱ��		(ms)
	int		nOverAllBitRate;		//�ļ��ܵı�����	bps
	int		nProgramNum;			//��Ŀ��
	MEDIA_INFO_LIB_ID3_INFO	 mFileID3Info; //�ļ�ID3��Ϣ
	MEDIA_INFO_PROGRAM_INFO mpFilePrograms;//��Ŀ��
};

class CPubMediaInfoLib
{
public:
	CPubMediaInfoLib(void);

	virtual int SetVideoName(const wchar_t *pVideoFileName) = 0;

	virtual const MEDIA_INFO_LIB_FILE_INFO  Get_File_Info( void) = 0;
	
	virtual ~CPubMediaInfoLib(void);
};

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(push)
#pragma pack(1)
	struct MEIDACREATETIME
	{
		int nYear;
		int nMonth;
		int nDay;
		int nHour;
		int nMinute ;
		int nSecond;

	};
#pragma pack(pop)

	CPubMediaInfoLib * CreatePubMediaInfoLib(void);

	// audio version
	//-1 ;err
	// 1; version 1; 
	//2 ; version 2;

	int  GetMp3Version(const wchar_t *pVideoFileName);

	bool GetImageSize(const wchar_t* image_file, int* width, int* height);

	bool GetCreateTimeInfo(MEIDACREATETIME &mtCreatTime,MEIDACREATETIME &mtModifyTime,const wchar_t *pVideoFileName);

	int __stdcall GetExifAngle(const wchar_t* pFileNanme);

#ifdef __cplusplus
}
#endif
