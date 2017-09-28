unit TransParam;

  {$MINENUMSIZE 4}

interface

uses
  Windows;

type

  // YV12ͼ�����ݽṹ����
  YV12Image = record
    y         : PByte;
    u         : PByte;
    v         : PByte;
    a         : PByte;        // Alpha ͨ������͸���ȣ�
    width     : Integer;
    height    : Integer;
    y_pitch   : Integer;
    u_pitch   : Integer;
    v_pitch   : Integer;
  end;
  PYV12Image = ^YV12Image;

  // ת�������ṹ����
  TTransParam = record
    szTransID : array [0..63] of Char;  // Transition ID
    fLength   : Single;                 // Transition ���ȣ�ʱ�䵥λ��
    fPos      : Single;                 // Transition ��ǰλ��

  	// ���²����ɲ�ͬ��ת��ʵ�ֶ���������
    nParam1   : Integer;
    nParam2   : Integer;
    nParam3   : Integer;
    nParam4   : Integer;
    
    fParam1   : Single;
    fParam2   : Single;
    fParam3   : Single;
    fParam4   : Single;
  end;
  PTTransParam = ^TTransParam;

type
  TRANSITION_API = procedure(imgOut : PYV12Image; const imgFrom : PYV12Image; const imgTo : PYV12Image; const trParam : PTTransParam); stdcall;

implementation

end.
