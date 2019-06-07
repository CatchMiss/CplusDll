// DLLApi4.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "DLLApi4.h"
#include <stdio.h>

// ���ǵ���������һ��ʾ��
DLLAPI4_API int nDLLApi4=0;

// ���ǵ���������һ��ʾ����
DLLAPI4_API int fnDLLApi4(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� DLLApi4.h
CDLLApi4::CDLLApi4()
{
    return;
}

/**************************************************************/

extern "C" __declspec(dllexport) int _stdcall func1(int a) 
{
	return 10 * a;
}

extern "C" __declspec(dllexport) void _stdcall func2(float in, float& out)
{
	out = 20 * in;
}

extern "C" __declspec(dllexport) void _stdcall func3(float* in, float* out, int len)
{
	for (int i = 0; i < len; i++)
	{
		out[i] = 30 * in[i];
	}
}

extern "C" __declspec(dllexport) void _stdcall func4(char* in, char* out, int len)
{
	printf("char* in %s\n", in);

	for (int i = 0; i < len - 1; i++)
	{
		out[i] = 'C';
	}
	out[len - 1] = '\0';

	printf("char* out %s\n", out);
}

struct param
{
	int p1;
	float p2;
};

extern "C" __declspec(dllexport) void _stdcall func5(param src, param& dest)
{
	dest.p1 = 50 * src.p1;
	dest.p2 = 50 * src.p2;
}


/*
typedef struct
{
	char* CameraID;
	char* CameraName;
}CAMERA_INFO;

typedef struct
{
	unsigned int uiTotal;
	CAMERA_INFO* stCameraInf;  
}CAMERA_INFO_LIST;

extern "C" __declspec(dllexport) void _stdcall GetDeviceList(CAMERA_INFO_LIST* pCameraList)
{
	unsigned int count = 3;
	CAMERA_INFO camera1, camera2, camera3;
	camera1.CameraID = "001";
	camera1.CameraName = "camera1";
	camera2.CameraID = "002";
	camera2.CameraName = "camera3";
	camera3.CameraID = "003";
	camera3.CameraName = "camera3";

	pCameraList->uiTotal = count;
	pCameraList->stCameraInf

}
*/
