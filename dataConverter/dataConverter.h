// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DATACONVERTER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DATACONVERTER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DATACONVERTER_EXPORTS
#define DATACONVERTER_API __declspec(dllexport)
#else
#define DATACONVERTER_API __declspec(dllimport)
#endif

// �����Ǵ� dataConverter.dll ������
class DATACONVERTER_API CdataConverter {
public:
	CdataConverter(void);
	// TODO:  �ڴ�������ķ�����
};

extern DATACONVERTER_API int ndataConverter;

DATACONVERTER_API int fndataConverter(void);
