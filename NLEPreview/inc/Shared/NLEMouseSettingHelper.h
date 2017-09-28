#ifndef NLE_MOUSE_SETTING_HELPER_H
#define NLE_MOUSE_SETTING_HELPER_H

#include "stdafx.h"

#include "NLEGraphics.h"

#include <string>
#include <vector>

class CNLESegmentMouseInfo
{
public:
	CNLESegmentMouseInfo(){}
	~CNLESegmentMouseInfo(){}

	//������100Ϊ��������0-100��ʾ0%-100%
	int scaleFactor; //����С�����ű�����0 - 500
	int opacity; //͸���ȣ� 0 - 100
	std::wstring highlightImgPath; //����ͼƬ·��


	NLERange range;
	std::wstring iconDirectory;
	std::wstring mouseImgPath;
	NLEPoint mouseImgHotspot; //�ȵ���������ͼ������Ͻǵ�����
	std::wstring clickedEffectImgPath;
	std::wstring doubleClickedEffectImgPath;
	std::wstring rightClickedEffectImgPath;
	std::wstring dragEffectImgPath;
};

class CNLEMouseSettingHelper
{
public:
	CNLEMouseSettingHelper();
	~CNLEMouseSettingHelper();

	/**
	@brief �������Ϣת����һ���ַ���
	*/
	std::wstring GetPropertyValue();

	/**
	@brief �����õİ��������Ϣ���ַ�������Ϊ�����Ϣ�ṹ
	*/
	HRESULT SetPropertyValue(std::wstring value);
	
	/**
	@brief ��ȡ�����Ϣ�εĸ���
	*/
	int SegmentCount();

	/**
	@brief ���һ�����ε���Ϣ
	*/
	HRESULT AddSegmentMouseInfo(CNLESegmentMouseInfo info);
	
	/**
	@brief ��ȡָ�������ε���Ϣ
	@param index ��ţ�ֵΪ[0, count-1]
	*/
	HRESULT GetSegmentMouseInfo(int index, CNLESegmentMouseInfo *pInfo);

	/**
	@brief ɾ��ָ��������
	@param index ��ţ�ֵΪ[0, count-1]
	*/
	HRESULT RemoveSegmentMouseInfo(int index);

	/**
	@brief ������е�������Ϣ
	*/
	HRESULT Clear();
	
private:
	std::vector<CNLESegmentMouseInfo> m_segmentMouseInfoVec;
};

#endif
