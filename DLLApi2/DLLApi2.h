// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DLLAPI2_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DLLAPI2_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DLLAPI2_EXPORTS
#define DLLAPI2_API __declspec(dllexport)
#else
#define DLLAPI2_API __declspec(dllimport)
#endif

// �����Ǵ� DLLApi2.dll ������
class DLLAPI2_API CDLLApi2 {
public:
	CDLLApi2(void);
	// TODO:  �ڴ�������ķ�����
};

extern DLLAPI2_API int nDLLApi2;

DLLAPI2_API int fnDLLApi2(void);
