// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BRIGE4MATLABANDOPENCV_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BRIGE4MATLABANDOPENCV_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef BRIGE4MATLABANDOPENCV_EXPORTS
#define BRIGE4MATLABANDOPENCV_API __declspec(dllexport)
#else
#define BRIGE4MATLABANDOPENCV_API __declspec(dllimport)
#endif
#include "dataConverter.h"
#include "mexFunctionCollector.h"
// �����Ǵ� Brige4MatlabAndOpencv.dll ������
class BRIGE4MATLABANDOPENCV_API CBrige4MatlabAndOpencv {
public:
	CBrige4MatlabAndOpencv(void);
	// TODO:  �ڴ�������ķ�����
};


extern BRIGE4MATLABANDOPENCV_API int nBrige4MatlabAndOpencv;

BRIGE4MATLABANDOPENCV_API int fnBrige4MatlabAndOpencv(void);
