// DLLApi2.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "DLLApi2.h"


// ���ǵ���������һ��ʾ��
DLLAPI2_API int nDLLApi2=0;

// ���ǵ���������һ��ʾ����
DLLAPI2_API int fnDLLApi2(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� DLLApi2.h
CDLLApi2::CDLLApi2()
{
    return;
}
