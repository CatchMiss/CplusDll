// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DLLAPI4_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DLLAPI4_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DLLAPI4_EXPORTS
#define DLLAPI4_API __declspec(dllexport)
#else
#define DLLAPI4_API __declspec(dllimport)
#endif

// �����Ǵ� DLLApi4.dll ������
class DLLAPI4_API CDLLApi4 {
public:
	CDLLApi4(void);
	// TODO:  �ڴ�������ķ�����
};

extern DLLAPI4_API int nDLLApi4;

DLLAPI4_API int fnDLLApi4(void);
