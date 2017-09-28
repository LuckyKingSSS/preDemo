/*! \file XMLReadCom.h
* \brief	�������У��ӿ�,
*/
#pragma once
#include <scombase.h>
#include "COMMacro.h"
//#include "CommonInterface.h"
#include "XMLRead.h"

/*!
* \class IXMLRead
* \brief �������У��ӿ� 
*/
// {C1FD2EEA-93C5-4828-A8F5-11C9BACB19FC}
DEFINE_GUID(IID_IXMLRead, 
		0xc1fd2eea, 0x93c5, 0x4828, 0xa8, 0xf5, 0x11, 0xc9, 0xba, 0xcb, 0x19, 0xfc);
EXTERN_C const IID IID_IXMLRead;
MACRO_MIDL_INTERFACE(IXMLRead,"C1FD2EEA-93C5-4828-A8F5-11C9BACB19FC")
:public IUnknown
{
	public:
		/*! \fn virtual STDMETHODIMP_(bool)initXml(BSTR ppName)
		* \brief ��ȡxml������
		* \param ppName [in] xml����·��
		* \retval ��ȡxml���Ƿ�ɹ�
		*/
		virtual STDMETHODIMP_(bool)initXml(BSTR ppName)=0;
		/*! \fn virtual STDMETHODIMP_(int)unintXml()
		* \brief ж��xml������
		* \retval ж��xml���Ƿ�ɹ�
		*/
		virtual STDMETHODIMP_(int)unintXml()=0;

		/*! \fn virtual STDMETHODIMP_(int)checkInputParam(userInputParam &userInputFileFourcc)
		* \brief У���û�����Ĳ��� 
		* \param userInputFileFourcc [in] �û����������Ƶ�������
		* \retval У����
		*/
		virtual STDMETHODIMP_(int)checkInputParam(userInputParam &userInputFileFourcc)=0;

		/*! \fn virtual STDMETHODIMP_(int)checkInputParam(userInputParam &userInputFileFourcc)
		* \brief У���û�����Ĳ��� 
		* \param userInputFileFourcc [in] �û����������Ƶ�������
		* \param errResult [in/out] ���󷵻�ֵ
		* \retval У����
		*/
		virtual STDMETHODIMP_(int)checkInputParamEx(userInputParam &userInputFileFourcc,retErrCheckResult* errResult = NULL)=0;
};



/*!
* \class IXMLReadLodaDLL
* \brief �ӿ� 
*/
// {03244199-C5F1-4dd1-AAF4-BD7704F63D71}
DEFINE_GUID(IID_IXMLReadLodaDLL, 
			0x3244199, 0xc5f1, 0x4dd1, 0xaa, 0xf4, 0xbd, 0x77, 0x04, 0xf6, 0x3d, 0x71);

EXTERN_C const IID IID_IXMLReadLodaDLL;
MACRO_MIDL_INTERFACE(IXMLReadLodaDLL,"03244199-C5F1-4dd1-AAF4-BD7704F63D71")
:public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(bool)initXml(BSTR ppName,WS_XML_PARSE_TYPE xmlParseType)
	* \brief ��ȡxml������
	* \param ppName [in] xml����·��
	* \retval ��ȡxml���Ƿ�ɹ�
	*/
	virtual STDMETHODIMP_(bool)initXml(BSTR ppName,WS_XML_PARSE_TYPE xmlParseType = XML_PARSE_FILE_DEMUX)=0;

	/*! \fn virtual STDMETHODIMP_(int)unintXml_EX()
	* \brief ж��xml������
	* \retval ж��xml���Ƿ�ɹ�
	*/
	virtual STDMETHODIMP_(int)unintXml_EX()=0;

	/*! \fn virtual STDMETHODIMP_(usrLoadFileDemuxDllParam *)GetFileDemuxDllNames(BSTR ppName,int &nDllNum)
	* \brief У���û�����Ĳ��� 
	* \param ppName [in] ��ѡ����������ļ��� ,��ppname = null,��ȡ���з�����
	* \param nDllNum [in][out] ��ȡ����ֵ��ָ������Ĵ�С��
	* \retval У����
	*/
	virtual STDMETHODIMP_(const usrLoadFileDemuxDllParam *)GetFileDemuxDllNames(BSTR ppName,int &nDllNum,DECODE_DEMUX_MODE_XML_TYPE modeType)=0;

	/*! \fn virtual STDMETHODIMP_(usrLoadFileDecodeDllParam *)GetFileDecodeDllNames(DWORD dwDecodeFourcc,int &nDllNum)
	* \brief У���û�����Ĳ��� 
	* \param dwFourcc [in] ��ѡ��������ĵ�����Ƶfourcc
	* \param nDllNum [in][out] ��ȡ����ֵ��ָ������Ĵ�С��
	* \retval У����
	*/
	virtual STDMETHODIMP_(const usrLoadFileDecodeDllParam *)GetFileDecodeDllNames(DWORD dwDecodeFourcc,int &nDllNum,DECODE_DEMUX_MODE_XML_TYPE modeType)=0;

	/*! \fn virtual STDMETHODIMP_(usrLoadFileDecodeDllParam *)GetFileEncodeDllNames(DWORD dwEncodeFourcc)
	* \brief У���û�����Ĳ��� 
	* \param dwFourcc [in] ��ѡ��������ĵ�����Ƶfourcc
	* \param nDllNum [in][out] ��ȡ����ֵ��ָ������Ĵ�С��
	* \retval У����
	*/
	virtual STDMETHODIMP_(const usrLoadFileEncodeDllParam *)GetFileEncodeDllNames(DWORD dwEncodeFourcc,int &nDllNum)=0;

	/*! \fn virtual STDMETHODIMP_(usrLoadFileMuxDllParam *)GetFileMuxDllNames(DWORD dwMuxFourcc)
	* \brief У���û�����Ĳ��� 
	* \param dwFourcc [in] ��ѡ��ϳ������ļ�fourcc
	* \param nDllNum [in][out] ��ȡ����ֵ��ָ������Ĵ�С��
	* \retval У����
	*/
	virtual STDMETHODIMP_(const usrLoadFileMuxDllParam *)GetFileMuxDllNames(DWORD dwMuxFourcc,int &nDllNum)=0;

};

/*!
* \class IXMLReadLossParams
8 \brief �������У��ӿ�
*/

// {A20D87DA-D759-49ef-85F7-F5C3668259F5}
DEFINE_GUID(IID_IXMLReadLossParams, 
			0xa20d87da, 0xd759, 0x49ef, 0x85, 0xf7, 0xf5, 0xc3, 0x66, 0x82, 0x59, 0xf5);
EXTERN_C const IID IID_IXMLReadLossParams;

MACRO_MIDL_INTERFACE(IXMLReadLossParams,"A20D87DA-D759-49ef-85F7-F5C3668259F5")
:public IUnknown
{
	public:
	/*! \fn virtual STDMETHODIMP_(bool)initXml_Loss(BSTR ppName)
	* \brief ��ȡxml������
	* \param ppName [in] xml����·��
	* \retval ��ȡxml���Ƿ�ɹ�
	*/
	virtual STDMETHODIMP_(bool)initXml_Loss(BSTR ppName)=0;

	/*! \fn virtual STDMETHODIMP_(int)unintXml_Loss()
	* \brief ж��xml������
	* \retval ж��xml���Ƿ�ɹ�
	*/
	virtual STDMETHODIMP_(int)unintXml_Loss()=0;

	/*! virtual STDMETHODIMP_(int) GetMatchFormatParams();
	* \brief ��ȡ����ƥ�������ʽ
	* \param dwFormatFourcc [in] �ļ���ʽFoucc
	* \param dwVideoForcc   [in] ��Ƶ����Foucc
	* \param dwFormatFourcc [in] ��Ƶ����Foucc
	* \param nFormatNum		[in][out] ƥ���ʽ��Ŀ
	* \retval У����
	*/
	virtual STDMETHODIMP_(int) CheckMatchFormatParams(LossInputFormatInfo& nLossInputFormatInfo,LossOutputFormatInfo & nLossOutputFormatInfo) = 0;
};


// {540A7D1C-96D7-49b9-84FD-A9E51A56ADEA}

MIDL_DEFINE_GUID(CLSID,CLSID_CXMLRead, 0x540a7d1c, 0x96d7, 0x49b9, 0x84, 0xfd, 0xa9, 0xe5, 0x1a, 0x56, 0xad, 0xea);

//EXTERN_C const CLSID CLSID_CXMLRead;
