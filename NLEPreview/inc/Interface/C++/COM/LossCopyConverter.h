/* ### WS@H Project:Multimedia_Platform ### */

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
#include "CTCommonExternal.h"

//struct ST_MEDIA_FILE_INFO;
//struct KeyFrameIndexArr;

enum CLIP_LOSSCOPY_MODE
{
	LOSSCOPY_SPLIT_BASE_ON_TIME,	
	LOSSCOPY_SPLIT_BASE_ON_SIZE
};

enum FILE_LOSSCOPY_MODE
{
	FILE_LOSSCOPY_MODE_SPLITER,//��һ���ļ����ָ�ɶ�������ļ�
	FILE_LOSSCOPY_MODE_MERGE, //��ȡ��ͬ�ļ�����ͬ���ϳ�һ���ļ���
	FILE_LOSSCOPY_MODE_STREAMMIX //��ȡ��ͬ�ļ��Ĳ�ͬ����ϳ�һ���ļ���
};

enum CALL_BACK_TYPE
{
	CALL_BACK_TYPE_PROCESS_CONVERTER,
	CALL_BACK_TYPE_PROCESS_KEYINDEX
};

enum MSG_LOSSCOPY_TYPE
{
	MSG_LOSSCOPY_COVERTER_TASK_BEGIN = 0,
	MSG_LOSSCOPY_COVERTER_TASK_END,		//���ڶ���ļ��ָ����task����
	MSG_LOSSCOPY_COVERTER_FILE_BEGIN, //�ļ�ת����ʼ
	MSG_LOSSCOPY_COVERTER_FILE_END,		//�ļ�ת������
	MSG_LOSSCOPY_COVERTER_CLIP_BEGIN,	//�ļ�clip�ο�ʼ
	MSG_LOSSCOPY_COVERTER_CLIP_END,		//�ļ�clip����
	MSG_LOSSCOPY_COVERTER_PROGRESS,		//ת���ܽ��ȣ��������ֵΪ���д��ϲ��ļ�ʱ��
	MSG_LOSSCOPY_KEYINDEX_PROGRESS,		//��ȡ����ת�����ȣ�
	MSG_LOSSCOPY_KEYINDEX_FILE_BEGIN,
	MSG_LOSSCOPY_KEYINDEX_FILE_END,
	MSG_LOSSCOPY_EXCEPTION_CLIP_END, //ת���쳣
	MSG_LOSSCOPY_COVERTER_CLIP_PROGRESS //��Էָÿ��CLIPת�����ȣ�����ÿ��CLIP����0��ʼ

};

//ÿһ����ļ�ID����
struct MERGE_LOSSCOPY_CHECK_ITEM_INFO
{
   __int64* nFileIdList;
	__int64 nListSize;

};

//�ϲ� ����
struct MERGE_LOSSCOPY_CHECK_RESULT_INFO
{
	MERGE_LOSSCOPY_CHECK_ITEM_INFO* pGrouplist;
	__int64 nListSize;
};




struct SPLITER_MSG_INFO
{
	__int64 nFileID;
	__int64 nClipIdx;
};

//CLIP TIEM
struct ClipTimeLoss
{
	__int64 dBeginTime;  //unit:1/10000000 s
	__int64 dLength;
	__int64 dFrameOffset; // package num
};

//CLIP SIZE
struct ClipSizeLoss
{
	__int64 nBeginPos;
	__int64 nSize;			//clip��С����λ�ֽ�
	__int64 dFrameOffset;
};

class         CWSSample;
/*!
* \class IMediaStreamEx
* \brief ��ȡ����Ϣ 
*/
// {35B968AB-69C3-4b2d-BB20-968F43886FEB}
DEFINE_GUID(IID_IMediaStreamEx, 
			0x35b968ab, 0x69c3, 0x4b2d, 0xbb, 0x20, 0x96, 0x8f, 0x43, 0x88, 0x6f, 0xeb);
EXTERN_C const IID IID_IMediaStreamEx;
MACRO_MIDL_INTERFACE(IMediaStreamEx, "35B968AB-69C3-4b2d-BB20-968F43886FEB")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP GetStreamInfo(IStreamInfo** ppStreamInfo)
	* \brief  ��ȡ��ǰ������Ϣ
	* \param ppStreamInfo [in / out] �������Ϣ�ӿ�
	* \retval ��ȡ���
	* \see IStreamInfo 
	*/
	virtual STDMETHODIMP GetStreamInfo(IStreamInfo** ppStreamInfo) = 0;

	/*! \fn virtual STDMETHODIMP ChangeStream(int nNewStreamID)
	* \brief  �任һ·��
	* \param nNewStreamID [in] ����ID
	* \retval �任���
	*/
	virtual STDMETHODIMP ChangeStream(int nNewStreamID) = 0;

	/*! \fn virtualSTDMETHODIMP_(CWSSample *) GetSampleEx(void)
	* \brief  ��ȡ��ǰ��֡(��Ƶ) �� Sample(��Ƶ)
	* \retval ��ȡ�Ľ��
	* \see CWSSample
	*/

	virtual STDMETHODIMP_(CWSSample *) GetSampleEx(void) = 0;

	/*! \fn virtual STDMETHODIMP_(int) Forward(void)
	* \brief  ǰ����һ֡(��Ƶ) �� ��һ��Sample (��Ƶ)
	* \retval 1 ��ʾ��ǰ��һ֡��0��ʾ�������
	*/
	virtual STDMETHODIMP_(int) Forward(void) = 0;


	/*! \fn virtual STDMETHODIMP_(int) Backward(void)
	* \brief  ������һ֡(��Ƶ) �� ��һ��Sample (��Ƶ)
	* \retval 1 ��ʾ�ɹ����˵���һ֡��0��ʾ����ʧ��
	*/
	virtual STDMETHODIMP_(int) Backward(void) = 0;

	/*! \fn virtual STDMETHODIMP_(double) Seek(double dTime, int accurate)
	* \brief seek��ĳ��ʱ���
	* \param dTime [in]  seek��ʱ���
	* \param accurate [in] �Ƿ�Ҫ��ȷseek
	* \retval seek����ʱ���
	*/
	virtual STDMETHODIMP_(double) Seek(double dTime, int accurate) = 0;

	/*! \fn virtual STDMETHODIMP_(int) NotifyStreamMessage(const ULONG  nMessage,const LONGLONG  nParam, void*  lpParam, void*  pPrivate)
	* \brief ֪ͨ��������
	* \retval 
	*/
	virtual STDMETHODIMP_(int) NotifyStreamMessage(const ULONG  nMessage,const LONGLONG  nParam, void*  lpParam, void*  pPrivate) = 0;
	
	/*! \fn virtualSTDMETHODIMP_(CWSSample *) GetEmptySampleEx(void)
	* \brief  ��ȡ��֡(��Ƶ) �� Sample(��Ƶ)
	* \retval ��ȡ�Ľ��
	* \see CWSSample
	*/

	virtual STDMETHODIMP_(CWSSample *) GetOriginSampleEx(void)=0;
};

//���Ȼص�
typedef HRESULT (__stdcall *MEDIALOSSCOPY_MULTI_CALLBACK)(void* pUserObj, UINT uMsg, void* pParam, LPARAM lParam);


/*!
* \class IMerge_LossCopy_Check_Info
* \brief IMerge_LossCopy_Check_Info�ӿ�
*/

// {FC48C7F4-4AB9-4ad0-AE80-BD24FC224DF3}
DEFINE_GUID( IID_IMerge_LossCopy_Check_Info, 0xfc48c7f4, 0x4ab9, 0x4ad0, 0xae, 0x80, 0xbd, 0x24, 0xfc, 0x22, 0x4d, 0xf3);
EXTERN_C const IID IID_IMerge_LossCopy_Check_Info;
MACRO_MIDL_INTERFACE(IMerge_LossCopy_Check_Info, "FC48C7F4-4AB9-4ad0-AE80-BD24FC224DF3")
: public IUnknown
{
	
	/*! \fn virtual STDMETHODIMP_(MERGE_LOSSCOPY_CHECK_RESULT) GetMergeGroupInfo(void)
	* \brief �ͷŻ�ȡ��Ϣ
	* \param void
	* \retval MERGE_LOSSCOPY_CHECK_RESULT ���
	*/

	virtual STDMETHODIMP_(MERGE_LOSSCOPY_CHECK_RESULT_INFO*) GetMergeGroupInfo(void) = 0;

	/*! \fn virtual STDMETHODIMP ReleaseMergeGroupInfo(MERGE_LOSSCOPY_CHECK_RESULT groupinfo);
	* \brief �ͷŻ�ȡ��Ϣ����
	* \param ��������MERGE_LOSSCOPY_CHECK_RESULT groupinfo
	* \retval
	*/
	virtual STDMETHODIMP ReleaseMergeGroupInfo(MERGE_LOSSCOPY_CHECK_RESULT_INFO* groupinfo) = 0;
};



/*!
* \class ILossCopyMediaInfo
* \brief ILossCopyMediaInfo�ӿ�
*/

// {104B3F4D-B9CB-48f1-9D3D-504B2494FEF2}
DEFINE_GUID(IID_ILossCopyMediaInfo, 
0x104b3f4d, 0xb9cb, 0x48f1, 0x9d, 0x3d, 0x50, 0x4b, 0x24, 0x94, 0xfe, 0xf2);
EXTERN_C const IID IID_ILossCopyMediaInfo;
MACRO_MIDL_INTERFACE(ILossCopyMediaInfo, "104B3F4D-B9CB-48f1-9D3D-504B2494FEF2")
: public IUnknown
{
	virtual STDMETHODIMP_(const ST_MEDIA_FILE_INFO*) GetFileMediaInfo() = 0;
};


/*!
* \class IMediaConverter
* \brief converter�ӿ� ,ʱ�䵥λ 1/ 10000000 ��
*/

// {FB138BF6-5614-4d3e-A1D7-33720929D77E}
DEFINE_GUID(IID_IMediaLossCopyConverter, 
0xfb138bf6, 0x5614, 0x4d3e, 0xa1, 0xd7, 0x33, 0x72, 0x9, 0x29, 0xd7, 0x7e);
EXTERN_C const IID IID_IMediaLossCopyConverter;
MACRO_MIDL_INTERFACE(IMediaLossCopyConverter, "FB138BF6-5614-4d3e-A1D7-33720929D77E")
: public IUnknown
{
	/*! \fn virtual STDMETHODIMP AddInputFile(const BSTR pInputPath)
	* \brief ���������ļ�
	* \param pInputPath [in]   �����ļ�
	* \retval  �ļ�ID ,-1��ʾ����ļ�ʧ��
	*/
	virtual STDMETHODIMP_(__int64) AddInputFile(const BSTR pInputPath) = 0;
	/*! \fn virtual STDMETHODIMP RemoveInputFile(__int64 nFileID)
	* \brief �Ƴ�ָ���ļ�
	* \param nFileID [in]   �����ļ�ID
	* \retval ���ý��
	*/
	virtual STDMETHODIMP RemoveInputFile(__int64 nFileID) = 0;
	/*! \fn virtual STDMETHODIMP  ClearAllInputFile(void)
	* \brief ��������ļ�
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP ClearAllInputFile(void) =0;

	/*! \fn virtual STDMETHODIMP SetOutputFolder(const BSTR pOutputPath)
	* \brief ��������ļ�
	* \param pOutputPath [in]   merge �� STREAMMIXģʽ����ȫ·������������������ļ���·������\\
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetOutputFolder(const BSTR pOutputPath) = 0;
	/*! \fn virtual STDMETHODIMP AddClipTime( __int64 nFileID ,ClipTimeLoss ctClipTime) 
	* \brief ����clipʱ��
	* \param nFileID [in]		�ļ�ID
	* \param ClipTimeLoss [in]   cliptime,����ļ���ȡ����<=1 ,��ôClipTimeLoss.dFrameOffset = -1
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP AddClipTime( __int64 nFileID ,ClipTimeLoss ctClipTime) = 0;
	/*! \fn virtual STDMETHODIMP RemoveClipTime( __int64 nFileID ,__int64 nClipIndex) 
	* \brief ���clipʱ��
	* \param nFileID [in]		�ļ�ID
	* \param nClipIndex [in]	CLIP��ID
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP RemoveClipTime( __int64 nFileID ,__int64 nClipIndex) = 0;
	/*! \fn virtual STDMETHODIMP GetClipTime(__int64 nFileID ,__int64 nClipIndex,ClipTimeLoss* ctClipTime) 
	* \brief �Ƴ�clipʱ��
	* \param nFileID [in]		�ļ�ID
	* \param nClipIndex [in]	CLIP��ID
	* \param ctClipTime [out]   clipʱ��
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP GetClipTime(__int64 nFileID ,__int64 nClipIndex,ClipTimeLoss* ctClipTime) = 0;
	/*! \fn virtual STDMETHODIMP SetClipTime(__int64 nFileID ,__int64 nClipIndex,ClipTimeLoss ctClipTime)
	* \brief ����clipʱ��
	* \param nFileID [in]		�ļ�ID
	* \param nClipIndex [in]	CLIP��ID
	* \param ctClipTime [out]   clipʱ��
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetClipTime(__int64 nFileID ,__int64 nClipIndex,ClipTimeLoss ctClipTime) = 0;


	/*! \fn virtual STDMETHODIMP AddClipSize(__int64 nFileID,ClipSizeLoss csClipSize) 
	* \brief ����clip��С
	* \param nFileID [in]		�ļ�ID
	* \param csClipSize [in]   clip��ʼ��С,Ĭ�ϴ��ļ���һ֡��ʼ����clip��С������clip ��clip��С����λ�ֽ�
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP AddClipSize(__int64 nFileID,ClipSizeLoss csClipSize) = 0;
	/*! \fn virtual STDMETHODIMP GetClipSize(__int64 nFileID, __int64 nClipIndex,ClipSizeLoss* csClipSize)
	* \brief ���clip��С
	* \param nFileID [in]		�ļ�ID
	* \param nClipIndex [in]	CLIP��ID
	* \param csClipSize [out]   clip��ʼʱ��,clip��С����λ�ֽ�
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP GetClipSize(__int64 nFileID, __int64 nClipIndex,ClipSizeLoss* csClipSize) = 0;


	/*! \fn virtual STDMETHODIMP_(__int64) GetFileClipCount(__int64 nFileID)
	* \brief ��ô������ļ�CLIP��Ŀ
	* \param nFileID [in]		�ļ�ID
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP_(__int64) GetFileClipCount(__int64 nFileID) = 0;


	/*! \fn virtual SetCallBack(MEDIALOSSCOPY_MULTI_CALLBACK pCallBack, void *pUserObj,CALL_BACK_TYPE cbType)
	* \brief ���ûص�����
	* \param pCallBack   [in]  �ص�����
	* \param pUserObject [in]  ���ܻص��Ķ���
	* \param cbType		 [in]  �ص�����
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP SetCallBack(MEDIALOSSCOPY_MULTI_CALLBACK pCallBack, void *pUserObj,CALL_BACK_TYPE cbType) = 0;

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
	/*! \fn virtual STDMETHODIMP SetFileLossCopyMode(FILE_LOSSCOPY_MODE nStyle, UINT dwLimit)
	* \brief ����Split����
	* \param nStyle [in]   �ļ�ת������
	* \param dwLimit [in]  �ļ�ת������[0:���������ؼ�֡�㣻1:�������ؼ���]
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetFileLossCopyMode(FILE_LOSSCOPY_MODE nStyle, UINT dwLimit) = 0;
	/*! \fn virtual STDMETHODIMP GetFileLossCopyMode(FILE_LOSSCOPY_MODE *pStyle, UINT *pLimit) = 0;
	* \brief ���Split����
	* \param nStyle [out]   �ļ�ת������
	* \param dwLimit [out]  �ļ�ת������[����]
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP GetFileLossCopyMode(FILE_LOSSCOPY_MODE *pStyle, UINT *pLimit) = 0;
	/*! \fn virtual STDMETHODIMP_(__int64) GetTargetCount(__int64 nFileID) ; 
	* \brief ���ת��Ŀ����Ŀ����
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP_(__int64) GetTargetCount(__int64 nFileID) = 0;
	/*! \fn virtual STDMETHODIMP GetTargetFileName(__int64 nFileID,__int64 nIndex, BSTR * ppFileName) = 0;
	* \brief ���ת��Ŀ���ļ���
	* \param nIndex [in]       Ŀ������ֵ
	* \param ppFileName [out]  Ŀ���ļ���
	* \retval  ��ý��
	*/
	virtual STDMETHODIMP GetTargetFileName(__int64 nFileID,__int64 nIndex, BSTR * ppFileName) = 0;

	/*! \fn virtual STDMETHODIMP STDMETHODIMP_(DWORD) Wait(UINT uMilliSecondsTimeOut = 0xFFFFFFFF) 
	* \brief �ȴ�ת������,����WIN��ģʽ��MAC���Բ��õ���
	* \param UINT uMilliSecondsTimeOut  �ȴ�ʱ��
	* \retval  �ȴ����EWS_OKת���ѽ��� EWS_TIMEOUT�ȴ���ʱ��ת��δ����
	*/
	virtual STDMETHODIMP_(DWORD) Wait(UINT uMilliSecondsTimeOut = 0xFFFFFFFF) = 0;

	/*! \fn virtual STDMETHODIMP_(int) CheckMergeInfo() = 0; 
	* \brief ��ȡ group��Ŀ��
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP_(IMerge_LossCopy_Check_Info*) CheckMergeInfo(void) = 0;

	/*! \fn virtual STDMETHODIMP GetFileKeyFrameIndex(__int64 nFileID,KeyFrameIndexArr** keyFrameIndexArr); 
	* \brief ��ȡ�ؼ�֡������Ϣ��
	* \param nFileID [in]       �ļ�����ֵ
	* \retval  ���عؼ�֡��������
	*/
	virtual STDMETHODIMP GetFileKeyFrameIndex(__int64 nFileID,KeyFrameIndexArr** keyFrameIndexArr) = 0;

	
	/*! \fn virtual STDMETHODIMP_(ILossCopyMediaInfo*) GetFileMediaInfo(__int64 nFileID); 
	* \brief ��ȡ�ؼ�֡������Ϣ
	* \param nFileID [in]      �ļ�ID
	* \param pFileMediaInfo [out]    �ļ���Ϣ 
	* \retval  ���عؼ�֡��������
	*/
	virtual STDMETHODIMP_(ILossCopyMediaInfo*) GetFileMediaInfo(__int64 nFileID) = 0;


	/*! \fn virtual STDMETHODIMP SelectFileStream( __int64 nFileID ,__int64 uStreamIndex,E_AV_STREAM_TYPE uStreamType) 
	* \brief ѡ���ļ� �Ľ���������
	* \param nFileID [in]		�ļ�ID
	* \param uStreamIndex [in]   ��id
	* \param uStreamType [in]    ������
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SelectFileStream( __int64 nFileID ,__int64 uStreamIndex,E_AV_STREAM_TYPE uStreamType) = 0;


	/*! \fn virtual STDMETHODIMP GetSelectStream( __int64 nFileID ,__int64 uStreamIndex,E_AV_STREAM_TYPE uStreamType,IMediaStream ** pMediaStream)
	* \brief ѡ���ļ� �Ľ���������
	* \param nFileID [in]		�ļ�ID
	* \param uStreamIndex [in]   ��id
	* \param uStreamType [in]    ������
	* \param pMediaStream [out]  ��
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP GetSelectStream( __int64 nFileID ,__int64 uStreamIndex,E_AV_STREAM_TYPE uStreamType,IMediaStreamEx ** pMediaStream) = 0;

	/*! \fn virtual STDMETHODIMP ComfirmDeMux(void)
	* \brief ����all stream ��ȷ��Demux�����ɹ����
	* \retval  ���ý��
	*/

	virtual STDMETHODIMP ComfirmDeMux(void) = 0;
	
	/*! \fn virtual STDMETHODIMP ComfirmMux(void)
	* \brief startǰ������ȷ��MUX�����ɹ����
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP ComfirmMux(void) = 0;

	/*! \fn virtual STDMETHODIMP_(int) GetSeekCap(__int64 nFileID)
	* \brief ѡ���ļ� �Ľ���������
	* \param nFileID [in]		�ļ�ID
	* \retval  ���ý�� 
	*/
	virtual STDMETHODIMP_(int) GetSeekCap(__int64 nFileID) =0;
	
	/*! \fn virtual STDMETHODIMP SetOutputFileExtentName(const BSTR ppExtentName)
	* \brief �����ļ���׺
	* \param ppExtentName [in]		�ļ���׺,.mp4,Ŀǰֻ�� �ϲ�ģʽ��Ч���Ժ�ȥ��
	* \retval  ���ý�� 
	*/
	
	virtual STDMETHODIMP SetOutputFileExtentName(const BSTR ppExtentName) = 0;


	/*! \fn virtual STDMETHODIMP ResetDemuxAndMux(void)
	* \brief ��ת����ɺ󣬵��øú���������Ŀǰ�Ѿ�������ز������ã��ָ�ת��ǰ��ʼ״̬��
	* \param 
	* \retval  ���ý�� 
	*/
	virtual STDMETHODIMP ResetDemuxAndMux(void) = 0;

	/*! \fn 	virtual STDMETHODIMP ChangeClipPosInFile(__int64 nFileID,__int64  nClipIndexOne,__int64  nClipIndexTwo);
	* \brief �ı�һ���ļ���clip�ε�ת��˳��
	* \param nFileID [in]		�ļ�ID
	* \param nClipIndexOne [in]	CLIP��ID
	* \param nClipIndexTwo [int] CLIP��ID
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP ChangeClipPosInFile(__int64 nFileID,__int64  nClipIndexOne,__int64  nClipIndexTwo)=0;


	/*! \fn 	virtual STDMETHODIMP ChangeFilePosInConvter(__int64 nFileIDOne,__int64 nFileIDTwo);
	* \brief �ı�ת���е��ļ���ת��˳��
	* \param nFileIDOne [__int64]		�ļ�ID
	* \param nFileIDTwo [__int64]		�ļ�ID
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP ChangeFilePosInConvter(__int64 nFileIDOne,__int64 nFileIDTwo)=0;

	
	/*! \fn 	virtual STDMETHODIMP MoveFilePosInConvter(__int64 nFileID,__int64 nPos) = 0;
	* \brief �ı�ת���е��ļ���ת��˳��,�ڵ�ǰλ��ǰ����
	* \param nFileID [__int64]		�ļ�ID
	* \param nPos  [__int64]		��ǰ�����ļ�˳�򣬴�0��ʼ
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP MoveFilePosInConvter(__int64* nFileID,__int64 nNum,__int64 nPos) = 0;

		/*! \fn 	virtual STDMETHODIMP CancelGetKeyFrameIndex(void) = 0;
	* \brief ȡ����ȡ�ؼ�֡����
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP CancelGetKeyFrameIndex(__int64 nFileID) = 0;




};

// {B4BFC2EE-D154-4139-9986-07A6BCC5D3F5}
//�����������CLSID_CMediaLossCopyConverter
MIDL_DEFINE_GUID(CLSID, CLSID_CMediaLossCopyConverter,0xb4bfc2ee, 0xd154, 0x4139, 0x99, 0x86, 0x7, 0xa6, 0xbc, 0xc5, 0xd3, 0xf5);
EXTERN_C const CLSID CLSID_CMediaLossCopyConverter;
//

