/**
@file   SubPicSearch.h 
@brief  �������������Ļ�ļ�

	�ܹ�ʶ��������Ļ�ļ�����ass/ssa/srt����������ʽ�����֣�
	- 1>.����ָ���ļ����µ�������Ļ����
	- 2>.������Ƶ�ļ������ļ����µģ���������Ƶ�ļ�ͬ������Ļ��
	- 3>.����ָ���ļ����µģ���������Ƶ�ļ�ͬ������Ļ
*/

#include <scombase.h>
#include "COMMacro.h"


/** 
@class 	 ISubPic 
@brief	 ��Ļ������,���ڻ�ȡ��Ļ�� �ļ��� ���� ������Ϣ.
*/

// {426726DA-3746-42bc-8F78-FA17AC1300B9}
DEFINE_GUID(IID_ISubPic, 0x426726da, 0x3746, 0x42bc, 0x8f, 0x78, 0xfa, 0x17, 0xac, 0x13, 0x0, 0xb9);
EXTERN_C const IID IID_ISubPic;
MACRO_MIDL_INTERFACE(ISubPic, "426726DA-3746-42bc-8F78-FA17AC1300B9")
: public IUnknown
{
public:

	/**
	@brief			��ȡ��·������Ļ�ļ���
	@param pName [out] :  �����·����Ļ�ļ���
	@return		HRESULT : ��������״̬
				- 1.S_OK    : ���óɹ�;
				- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetName(BSTR *pName) = 0;

	/**
	@brief			��ȡ��Ļ����������Ϣ
	@param pDescription [out] : ���渽��������Ϣ
	@return		HRESULT : ��������״̬
				- 1.S_OK    : ���óɹ�;
				- 2.S_FALSE : ����ʧ��;
	@note		�ú�����ʱΪ��ʹ��,��ȡ������ϢΪNULL;
	*/
	virtual STDMETHODIMP GetDescription(BSTR *pDescription) = 0;
};


/** 
@class 	 ISubPics 
@brief	 ��Ļ�����༯��,��ISubPic�ļ��ϱ�ʾ������.
*/


// {460A57D2-6369-451f-965C-01C7C4222BFE}
DEFINE_GUID(IID_ISubPics, 0x460a57d2, 0x6369, 0x451f, 0x96, 0x5c, 0x1, 0xc7, 0xc4, 0x22, 0x2b, 0xfe);
EXTERN_C const IID IID_ISubPics;
MACRO_MIDL_INTERFACE(ISubPics, "460A57D2-6369-451f-965C-01C7C4222BFE")
: public IUnknown
{
public:
	
	/**
	@brief			��ȡ�����������Ļ��.
	@return			int : ������������Ļ��Ŀ.
	*/
	virtual STDMETHODIMP_(int) GetCount() = 0;

	/**
	@brief			��ȡָ����������Ļ������.
	@param nIndex [in] : ������Ļ����
	@param ppItem [out] : ISubPic���͵�ָ���ָ��
	@return		HRESULT : ��������״̬
				- 1.S_OK    : ���óɹ�;
				- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetItem(int nIndex, ISubPic** ppItem) = 0;	
};

/** 
@class 	 ISubPicSearch 
@brief	 ��Ļ������,���ò�ͬ��������ʽ,������Ļ��������.
*/

// {F100E8F6-63A7-4100-A4B1-5D0D013FD285}
DEFINE_GUID(IID_ISubPicSearch, 	0xf100e8f6, 0x63a7, 0x4100, 0xa4, 0xb1, 0x5d, 0xd, 0x1, 0x3f, 0xd2, 0x85);
EXTERN_C const IID IID_ISubPicSearch;
MACRO_MIDL_INTERFACE(ISubPicSearch, "F100E8F6-63A7-4100-A4B1-5D0D013FD285")
: public IUnknown
{
public:

	/**
	@brief				 	����ͬ������ʽ,������Ļ
	@param pFolder	[in]: 	  ������Ļ�����ļ���
	@param pVideoPath [in] 	: 	 ������Ƶ�ļ�����·��
	@return				 	ISubPics : ������Ļ�ļ�����
	@note				 
			- 1.���pFolderΪNULL��pVideoPath��NULL����ô����VideoPath�����ļ����£�����Ƶ�ļ�����ͬ�������Ļ��;
			- 2.���pFolder��NULL�� pVideoPathΪNULL�� ��ô�������ļ��������е������Ļ�ļ�;
			- 3.���pFolderΪ��NULL��pVideoPath��NULL����ô����pFolder�£�����Ƶ�ļ�ͬ���������Ļ�ļ�;
			- 4.���pFolderΪNULL, pVideoPathΪNULL�� �Ƿ���			
	*/
	virtual STDMETHODIMP_(ISubPics *) CreateSubPics(const BSTR pFolder, const BSTR pVideoPath) = 0;
};

// {5F44370F-215A-440e-A913-182826DA1944}
//�����������subPicSearch
MIDL_DEFINE_GUID(CLSID, CLSID_CSubPicSearch, 0x5f44370f, 0x215a, 0x440e, 0xa9, 0x13, 0x18, 0x28, 0x26, 0xda, 0x19, 0x44);
EXTERN_C const CLSID CLSID_CSubPicSearch;
