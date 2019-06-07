C++ 动态库的导出与引用

一、导出

	a：使用 __declspec(dllexport), 加extern"C"使用C语言风格导出
		
	extern "C" __declspec(dllexport) int _stdcall func(int a, int b);
		
		1、在每个导出的函数名前加标识符
		2、Build生成动态库，会同时生成.dll和.lib文件

	b: 使用模块定义（.def）


	c: 托管(CLI)dll, 与C#契合




二、使用
	
	a: C#
		
		静态加载：

			1、using System.Runtime.InteropServices;
			2、定义：
				[DllImport("ExpDll.dll")]
				private static extern int cpp_exp_add(int a, int b);
			3、调用cpp_exp_add（）；

			注意：CallingConvention=CallingConvention.Cdecl

		动态加载：
	
	
	b: C++

		静态加载：
			#pragma comment(lib,"myDll.lib")
			extern "C" __declspec(dllimport) int _stdcall func(int a, int b);
			然后在代码在直接调用func();
			配置如下:（非常关键）
				项目->属性->配置属性->VC++ 目录-> 在“包含目录”里添加头文件testdll.h所在的目录
				项目->属性->配置属性->VC++ 目录-> 在“库目录”里添加头文件testdll.lib所在的目录
				项目->属性->配置属性->链接器->输入-> 在“附加依赖项”里添加“testdll.lib”（若有多个 lib 则以空格隔开）

		动态加载：
			HINSTANCE hInst;
			hInst = LoadLibrary(L"myDll.dll");
            typedef int(*FUNCPTR)(int a, int b);
			FUNCPTR myfunc = (FUNCPTR)GetProcAddress(hInst, "func");
			FreeLibrary(hInst);

	c: C#使用托管dll
		1、C++定义 public ref类（参考CLIDll）
		2、C++项目 属性--->常规--->公共语言clr(可解决第一步中报错问题)
		3、生成dll
		4、C#项目 引用--->项目（CLIDLLL）
		5、C#中直接new
