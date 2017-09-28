/*! \file CheckEncParams.h
* \brief							У���ⲿ����ı������
* Detailed							���ڶ��ⲿ���������Ƶ������������Ҷ�Ӧ������Ƶ�������������
								��Ӧ�Ĳ���У������������У����
*/
#pragma once
#include <scombase.h>
#include "COMMacro.h"
#include "ConverterType.h"
struct EncodeParam;
/*!
* \class ICheckEncParams
* \brief �Ա����������У��
*/

// {58FE100C-DCD4-49db-9930-336174CC0ECC}
DEFINE_GUID(IID_ICheckEncParams, 
			0x58fe100c, 0xdcd4, 0x49db, 0x99, 0x30, 0x33, 0x61, 0x74, 0xcc, 0xe, 0xcc);
EXTERN_C const IID IID_IID_ICheckEncParams;
MACRO_MIDL_INTERFACE(ICheckEncParams, "58FE100C-DCD4-49db-9930-336174CC0ECC")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP CheckEncParams(EncodeParam *m_EncParams) 
	* \brief  ��ȡ��������
	* \param  m_EncParams [in / out] �������
	* \retval �����У���Ĳ�����У���󴫳�
	*/
	virtual STDMETHODIMP CheckEncParams(EncodeParam *m_EncParams) = 0;
};

//�����������
MIDL_DEFINE_GUID(CLSID, CLSID_CCheckEncParams, 0xf1eb87e5, 0x6940, 0x42b6, 0xb4, 0xce, 0x20, 0x8a, 0xa7, 0x69, 0x00, 0x20);

EXTERN_C const CLSID CLSID_CCheckEncParams;