C++ ��̬��ĵ���������

һ������

	a��ʹ�� __declspec(dllexport), ��extern"C"ʹ��C���Է�񵼳�
		
	extern "C" __declspec(dllexport) int _stdcall func(int a, int b);
		
		1����ÿ�������ĺ�����ǰ�ӱ�ʶ��
		2��Build���ɶ�̬�⣬��ͬʱ����.dll��.lib�ļ�

	b: ʹ��ģ�鶨�壨.def��


	c: �й�(CLI)dll, ��C#����




����ʹ��
	
	a: C#
		
		��̬���أ�

			1��using System.Runtime.InteropServices;
			2�����壺
				[DllImport("ExpDll.dll")]
				private static extern int cpp_exp_add(int a, int b);
			3������cpp_exp_add������

			ע�⣺CallingConvention=CallingConvention.Cdecl

		��̬���أ�
	
	
	b: C++

		��̬���أ�
			#pragma comment(lib,"myDll.lib")
			extern "C" __declspec(dllimport) int _stdcall func(int a, int b);
			Ȼ���ڴ�����ֱ�ӵ���func();
			��������:���ǳ��ؼ���
				��Ŀ->����->��������->VC++ Ŀ¼-> �ڡ�����Ŀ¼�������ͷ�ļ�testdll.h���ڵ�Ŀ¼
				��Ŀ->����->��������->VC++ Ŀ¼-> �ڡ���Ŀ¼�������ͷ�ļ�testdll.lib���ڵ�Ŀ¼
				��Ŀ->����->��������->������->����-> �ڡ��������������ӡ�testdll.lib�������ж�� lib ���Կո������

		��̬���أ�
			HINSTANCE hInst;
			hInst = LoadLibrary(L"myDll.dll");
            typedef int(*FUNCPTR)(int a, int b);
			FUNCPTR myfunc = (FUNCPTR)GetProcAddress(hInst, "func");
			FreeLibrary(hInst);

	c: C#ʹ���й�dll
		1��C++���� public ref�ࣨ�ο�CLIDll��
		2��C++��Ŀ ����--->����--->��������clr(�ɽ����һ���б�������)
		3������dll
		4��C#��Ŀ ����--->��Ŀ��CLIDLLL��
		5��C#��ֱ��new
