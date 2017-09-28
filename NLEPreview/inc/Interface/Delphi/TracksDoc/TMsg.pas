////////////////////////////////////////////////////////////////////////////
// TMsg.pas
//==========================================================================
// ����    �� ����Timeline���ⲿ���͵���Ϣ ��Timeline���յ�������Ϣ
// ����ʱ�䣺 2005-08-12
// ������  �� �Ԫ
// �޶�    �� 
//==========================================================================

unit
	TMsg;


interface

uses
    Windows;

// Timeline��Ϣ���������
const

//==========================================================================
// ��ҪCallback��ϢID

// �ĵ�Message
TCM_UPDATE							= 1;		// ʱ���������Ѿ�����
TCM_CLIP_PARAM						= 2;		// Clip���������ı�
TCM_ADD_CLIPS						= 3;		// �������µ�Clip
TCM_DELETE_CLIPS					= 4;		// ��Clip��ɾ�� wParam - ɾ����Ԫ�ظ��� lParamΪָ��HCLIP������ָ�� ���ܰ���ת��Clip
TCM_CLIP_SELCET_CHANGE				= 5;		// Clipѡ��״̬�����ı䣬 wParam - ѡ��״̬��Clip������ lParam - ѡ���Ƿ�����
TCM_DELETE_ALL_CLIPS				= 6;		// ����Clip��ɾ��

TCM_CLIP_STATE						= 100;		// Clip״̬�����ı� lParam - clipָ�� HCLIP
TCM_SELECT_ALL						= 101;		// ѡ��������clip
TCM_SELECT_CLEAR_ALL				= 102;		// �������clip��ѡ��״̬
TCM_MOVE_CLIPS						= 103;		// ��Clip���ƶ�

TCM_DOC_MSG_MAX						= 299;		// �ĵ�������Ϣ֪ͨ���ֵ 


//---------------------------------------------------------------------------
// ��ͼMessage
TCM_TIMELINE_MOVING					= 302;		// ʱ�����ƶ���Ϣ�������ƶ�����lParamΪָ��doubleʱ�����ݵ�ָ��
TCM_TIMELINE_MOVED					= 303;		// ʱ�����ƶ���Ϣ���ƶ���ϣ���lParamΪָ��doubleʱ�����ݵ�ָ��
TCM_ZOOM_IN							= 304;		// ��ͼ�Ŵ�wParamΪ0-9֮�����������ʾ��ʾ�����ȼ���һ��10����lParamΪָ����ͼdouble��ʼʱ�����ݵ�ָ��
TCM_ZOOM_OUT						= 305;		// ��ͼ��С������ͬTMI_ZOOM_IN
TCM_PAN								= 306;		// ��ͼƽ�ƣ�lParamΪָ����ͼdouble��ʼʱ�����ݵ�ָ��
										 
//---------------------------------------------------------------------------
// ����Message							 
TCM_CLIPS_LOAD_PROGRESS				= 500;		// ���ڼ�����Ƭ�ļ� lParam - ���Ȱٷֱ� (0, 100)
TCM_CLIP_CLICK						= 510;		// Clip������ lParamΪ��������HCLIP���
TCM_CLIP_DOUBLECLK					= 511;		// Clip��˫�� lParamΪ��˫����HCLIP���
TCM_CONTEXT_MENU					= 512;		// �����Ĳ˵���RButtonClick  wParam - MAKEWPARAM(x, y) lParam - Ϊ�������HCLIP���
TCM_OVER_CLIP_COUNT					= 520;		// Timeline�еķ�ת��Clip�����Ѿ��ﵽ���ֵ
//TCM_PRE_DELETE_CLIPS				= 521;		// Clip����ɾ�� lParamΪָ���û����ݵ�����ָ�룬����Ϊ0�����





//==========================================================================
// Timeline���յ���Ҫ������ϢID

//TCC_DELETE_SELECTED_CLIPS			= 5001;	// ɾ������ѡ�е�Clips
//TCC_DELETE_ALL_CLIPS				= 5002;	// ɾ������Clips
TCC_SWITCH_VIEWMODE					= 5003;	// 
TCC_SET_VIEWMODE					= 5004;	// wParam: 0 - Timeline Mode  1 - Storyboard View Mode
TCC_GET_VIEWMODE					= 5005;	// return: 0 - Timeline Mode  1 - Storyboard View Mode
TCC_STORYBOARD_ONLY					= 5006;	// ��ʹ�ù��°�ģʽ
//TCC_APPLY_EFFECT_TO_SELECTED		= 5007;	// Ӧ����Ч��ѡ�е�Clip  wParam - ��Ч���ȣ����룩  lParam - ��ЧID���ַ���ָ�룩
TCC_ENSURE_VISIBLE_CLIP				= 5008;	// ��ָ��Clip���ڿɼ�״̬ wParam - ��ƬԪ��������
TCC_ON_HOME							= 5009;	// ��ͼ������ͷ��
TCC_ON_END							= 5010;	// ��ͼ������β��
//TCC_CAN_APPLY_EFFECT_TO_SELECTED	= 5011;	// �Ƿ����Ӧ����Ч��ѡ�� ���� 0 - ���ܣ� 1 - ��
//TCC_SELECTED_CLIP_COUNT				= 5012;	// ����ѡ�е�Clip���� ����ý���ת��Clip
//TCC_SELECTED_CAN_PREVIEW			= 5013;	// ���� 1 - ��Ƭѡ����������Ԥ��  0 - ������Ԥ��				
//TCC_ADD_CLIPS						= 5014;	// ���Clip wParam = MAKEWPARAM(nCount, nDefultLength)  lParam - const wchar_t*szFileNameArray[]
//TCC_APPLY_EFFECT_TO_ALL				= 5015;	// Ӧ����Ч������Clip  wParam - ��Ч���ȣ����룩  lParam - ��ЧID���ַ���ָ�룩
//TCC_RANDOM_EFFECT_TO_ALL			= 5016;	// Ӧ�������Ч������Clip  wParam - ��Ч���ȣ����룩
TCC_SET_TIME						= 5020;	// ����ʱ����λ�� lParam - double����ʱ�����ݵ�ַָ��
										  
TCC_SHOW_TRANSCLIP					= 8000;	// wParam: 1 - ��ʾת��  0 - ����ת��
TCC_ENSURE_CLIP						= 8001;	// ������ͼ��ʹ����ΪwParam��Clip�ɼ�
//TCC_STORYBOARD_THUMBNAIL_SIZE		= 8002;	// ���°�����ͼ�ߴ���� lParam
//TCC_STORYBOARD_TIMEMODE				= 8003;	// ���°�ʱ����ʾ��ʽ��0 - �� 1 - ʱ���֣���
										  
TCC_STORYBOARD_GETPARAM				= 8004;	// ����ȡ�ù��°������lParam - ָ��StoryboardOptions�ṹ��ָ��
TCC_STORYBOARD_SETPARAM				= 8005;	// ���ù��°������lParam - ָ��StoryboardOptions�ṹ��ָ��
										  
// ���°�����ṹ
type
	StoryboardOptions = record 

	nImageAreaWidth : Integer;	// ͼ�������
	nTransAreaWidth : Integer;	// ת�������

	nTransWidth : Integer;		// ת������ͼ���
	nTransHeight : Integer;		// ת������ͼ�߶�

	nImageBorderLeft : Integer;	// ͼ����߿���
	nImageBorderTop : Integer;	// ͼ���ϱ߿�߶�
	nImageBorderRight : Integer;// ͼ���ұ߿���
	nImageBorderBottom : Integer;// ͼ���±߿�߶�

	nBottomAreaHeight : Integer;// �ײ�Ԥ���߶�

	nImageEditWidth : Integer;	// ͼ��༭�򳤶�
	nEditHeight : Integer;		// �༭��߶�

	bTransVisible : BOOL;		// ת���Ƿ�ɼ�
	uImageLengthFlag : UINT;	// ImageƬ�γ����� 0 - ���ɼ�  1 - �ɼ� ���ܱ༭  3 - �ɼ� ���Ա༭ 
	uTransLengthFlag : UINT;	// TransƬ�γ����� 0 - ���ɼ�  1 - �ɼ� ���ܱ༭  3 - �ɼ� ���Ա༭ 	

	uTimeMode : UINT;			// 0 - �루ֻ��������������   
								// 1 - �루��������С����	��Ŀǰ��֧�֣�    
								// 2 - ʱ:��:��:֡			��Ŀǰ��֧�֣�    
								// 3 - ʱ:��:��.��/100		��Ŀǰ��֧�֣�   
								
	nMaxClips : Integer;		// ���clip���� ����ת�� 0 Ϊ������
	uEditCtrlFlag : UINT;		// 0 - ���Խ����ⲿ�������ݡ�clip���Խ���˳�򡢿���ɾ��
								// 1 - �����Խ����ⲿ�������ݡ�clip�����Խ���˳�򡢲�����ɾ��

end;


// ...

implementation

end.


