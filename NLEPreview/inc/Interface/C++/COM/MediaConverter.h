
/*! \file MediaConverter.h
* \brief							ת�����ֽӿ�����
* Detailed
*IMediaConverter�ӿ��ṩ�ˣ���ȡ�Լ��صı���ģ����Ϣ�����ñ�������������ļ������Ϣ��ת�����Ƶķ�����
*Ӧ�ò����ͨ������GetEncodeParam������ȡ��IMediaEncParam�ӿڣ��������ñ��������4.0����ǰ�������仯���ǣ�
*�ṹ��VideoParam��AudioParam�����StreamParam���½ṹ��ʹ��Buffer������������еı��������
*SetFileParam�������������ļ���һЩ��Ϣ����ID3��
*/

#pragma once
#include <scombase.h>
#include "COMMacro.h"
#include "ConverterType.h"
#include "CallBack.h"
#include "CommonInterface.h"

#define SPLIT_BASE_ON_NONE		0
#define SPLIT_BASE_ON_TIME		1
#define SPLIT_BASE_ON_SIZE		2


/*!
* \class IMediaEncParam
* \brief ��������ӿ� 
*/

// {635AF5AC-3D40-4ca6-83B2-392E316345E0}
DEFINE_GUID(IID_IMediaEncParam, 
			0x635af5ac, 0x3d40, 0x4ca6, 0x83, 0xb2, 0x39, 0x2e, 0x31, 0x63, 0x45, 0xe0);
EXTERN_C const IID IID_IMediaEncParam;
MACRO_MIDL_INTERFACE(IMediaEncParam, "635AF5AC-3D40-4ca6-83B2-392E316345E0")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP SetFourCC(UINT dwFourCC)
	* \brief ���ñ���Forcc
	* \param dwFourCC [in] ����Forcc
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetFourCC(UINT dwFourCC) = 0;
	/*! \fn virtual STDMETHODIMP_(UINT) GetFourCC(void)
	* \brief  ��ñ���Forcc
	* \retval ��ý��
	*/
	virtual STDMETHODIMP_(UINT) GetFourCC(void) = 0;
	/*! \fn virtual STDMETHODIMP SetUseTwoPass(int bUse)
	* \brief ����2pass��־
	* \param bUse [in] 2pass��־
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetUseTwoPass(int bUse) = 0;
	/*! \fn virtual STDMETHODIMP_(int) GetUseTwoPass(void)
	* \brief  ���2pass��־
	* \retval ��ý��
	*/
	virtual STDMETHODIMP_(int) GetUseTwoPass(void)=0;
	/*! \fn virtual STDMETHODIMP SetFileParam(const FileInfoParam * pFileParam)
	* \brief �����ļ���Ϣ����
	* \param pFileParam [in] �ļ�����
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetFileParam(const FileInfoParam * pFileParam) = 0;
	/*! \fn virtual STDMETHODIMP_(const FileInfoParam *) GetFileParam(void)
	* \brief ����ļ���Ϣ����
	* \retval  FileInfoParam�ṹ
	*/
	virtual STDMETHODIMP_(const FileInfoParam *) GetFileParam(void) = 0;
	/*! \fn virtual STDMETHODIMP SetEncParam(AV_STREAM_TYPE streamType, const StreamParam *pStreamParam)
	* \brief ���ñ������
	* \param streamType [in]   ���õ�������  
	* \param pStreamParam [in] ���õ�������
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetEncParam(AV_STREAM_TYPE streamType, const StreamParam *pStreamParam) = 0;
	/*! \fn virtual STDMETHODIMP_(const StreamParam *) GetEncParam(AV_STREAM_TYPE streamType)
	* \brief ��ñ������
	* \param streamType [in] ������  
	* \retval  ������
	*/
	virtual STDMETHODIMP_(const StreamParam *) GetEncParam(AV_STREAM_TYPE streamType) = 0;
	/*! \fn virtual STDMETHODIMP_(__int64) GetEstimateDiskSpace(void) 
	* \brief   ����ת����Ҫ�Ĵ��̿ռ�
	* \retval  ����ת����Ҫ�Ĵ��̿ռ�
	*/
	virtual STDMETHODIMP_(__int64) GetEstimateDiskSpace(void) = 0;
};

/*!
* \class IMediaConverter
* \brief converter�ӿ� 
*/

// {9684898A-3297-4da3-9264-6AAA5ED56600}
DEFINE_GUID(IID_IMediaConverter, 
			0x9684898a, 0x3297, 0x4da3, 0x92, 0x64, 0x6a, 0xaa, 0x5e, 0xd5, 0x66, 0x0);
EXTERN_C const IID IID_IMediaConverter;
MACRO_MIDL_INTERFACE(IMediaConverter, "9684898A-3297-4da3-9264-6AAA5ED56600")
: public IUnknown
{
	/*! \fn virtual STDMETHODIMP SetOutputFile(const BSTR pOutputPath)
	* \brief ��������ļ�
	* \param pOutputPath [in]   ����ļ�
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetOutputFile(const BSTR pOutputPath) = 0;
	/*! \fn virtual STDMETHODIMP GetEncodeParam(IMediaEncParam** pMediaEncParam)
	* \brief �õ���������ӿ�
	* \param pMediaEncParam [out]  ��������ӿ�
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP GetEncodeParam(IMediaEncParam** pMediaEncParam) = 0;
	/*! \fn virtual STDMETHODIMP SetClipTime(double dBeginTime, double dLength) 
	* \brief ����clipʱ��
	* \param dBeginTime [in]   clip��ʼʱ��
	* \param dLength [in]      clip����
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetClipTime(double dBeginTime, double dLength) = 0;
	/*! \fn virtual STDMETHODIMP GetClipTime(double *pBeginTime, double *pLength)
	* \brief ���clipʱ��
	* \param dBeginTime [out]   clip��ʼʱ��
	* \param dLength [out]      clip����
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP GetClipTime(double *pBeginTime, double *pLength) = 0;
	/*! \fn virtual SetCallBack(MULTI_CALLBACK pCallBack, void *pUserObject)
	* \brief ���ûص�����
	* \param pCallBack   [in]  �ص�����
	* \param pUserObject [in]  ���ܻص��Ķ���
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP SetCallBack(MULTI_CALLBACK pCallBack, void *pUserObj) = 0;
	/*! \fn virtual STDMETHODIMP SetMediainfoTime(double mediatime)
	* \brief   ����ת��ý��ʱ�䳤��
	* \param mediatime   [in]  ý��ʱ�䳤��
	* \retval  �� 
	*/
	virtual STDMETHODIMP SetMediainfoTime(double mediatime)=0;
	/*! \fn virtual STDMETHODIMP Start(void) 
	* \brief   ��ʼת��
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Start(void) = 0;
	/*! \fn virtual STDMETHODIMP Pause(void) 
	* \brief   ת����ͣ
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Pause(void) = 0;
	/*! \fn virtual STDMETHODIMP Resume(void) 
	* \brief   �ָ�ת��
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Resume(void) = 0;
	/*! \fn virtual STDMETHODIMP Stop(void) 
	* \brief   ֹͣת��
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Stop(void) = 0;
	/*! \fn virtual STDMETHODIMP SetSplitParam(int nStyle, UINT dwLimit)
	* \brief ����Split����
	* \param nStyle [in]   Split����
	* \param dwLimit [in]  Split����
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetSplitParam(int nStyle, UINT dwLimit) = 0;
	/*! \fn virtual STDMETHODIMP GetSplitParam(int *pStyle, UINT *pLimit)
	* \brief ���Split����
	* \param nStyle [out]   Split����
	* \param dwLimit [out]  Split����
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP GetSplitParam(int *pStyle, UINT *pLimit) = 0;
	/*! \fn virtual STDMETHODIMP_(int) GetTargetCount(void) 
	* \brief ���ת��Ŀ����Ŀ����
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP_(int) GetTargetCount(void) = 0;
	/*! \fn virtual STDMETHODIMP GetTargetFileName(int nIndex, BSTR * ppFileName)
	* \brief ���ת��Ŀ���ļ���
	* \param nIndex [in]       Ŀ������ֵ
	* \param ppFileName [out]  Ŀ���ļ���
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP GetTargetFileName(int nIndex, BSTR * ppFileName) = 0;
};


//�����������MediaConverter
MIDL_DEFINE_GUID(CLSID, CLSID_CMediaConverter, 0x7e55d7f9, 0x454a, 0x4d4c, 0xbd, 0x2d, 0x8f, 0xec, 0x18, 0x7b, 0x65, 0x7f);

EXTERN_C const CLSID CLSID_CMediaConverter;

// {235FEC1A-B7E6-4fab-B89F-0743344E484A}
//�����������CLSID_CLossLessCopy
MIDL_DEFINE_GUID(CLSID, CLSID_CLossLessCopy, 0x235fec1a, 0xb7e6, 0x4fab, 0xb8, 0x9f, 0x7, 0x43, 0x34, 0x4e, 0x48, 0x4a);

EXTERN_C const CLSID CLSID_CLossLessCopy;
