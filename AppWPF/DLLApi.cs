using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.InteropServices;

namespace AppWPF
{
    static class DLLApi
    {
        //返回参数
        [DllImport(@"DLLApi4.dll", EntryPoint = "func1", CallingConvention = CallingConvention.StdCall)]
        public static extern int func1(int a);

        //通过参数返回
        [DllImport(@"DLLApi4.dll", EntryPoint = "func2", CallingConvention = CallingConvention.StdCall)]
        public static extern void func2(float in_f, ref float out_f);

        //通过参数返回数组
        [DllImport(@"DLLApi4.dll", EntryPoint = "func3", CallingConvention = CallingConvention.StdCall)]
        public static extern void func3(float[] in_fs, float[] out_fs, int len);

        //字符串指针作为输入\输出参数，可以使用byte[] 和MarshalAs来解决。(推荐Marshal)
        [DllImport(@"DLLApi4.dll", EntryPoint = "func4", CallingConvention = CallingConvention.StdCall)]
        public static extern void func4_byte(byte[] src, byte[] dest, int len);
        [DllImport(@"DLLApi4.dll", EntryPoint = "func4", CallingConvention = CallingConvention.StdCall)]
        public static extern void func4_marshal([MarshalAs(UnmanagedType.LPStr)]string src,  [Out, MarshalAs(UnmanagedType.LPStr)]StringBuilder dest, int len);

        //Sequential,顺序布局
        //Explicit,精确布局
        [System.Runtime.InteropServices.StructLayout(LayoutKind.Sequential)]
        public struct param
        {
            public int p1;
            public float p2;
        }

        //结构体作为参数
        [DllImport(@"DLLApi4.dll", EntryPoint = "func5", CallingConvention = CallingConvention.StdCall)]
        public static extern void func5(param src, ref param dest);

        /*
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
        public struct CAMERA_INFO
        {
            String CameraID;
            String CameraName;
        }
        public struct CAMERA_INFO_LIST
        {
            uint uiTotal;
            CAMERA_INFO[] stCameraInf;
        }

        [DllImport(@"DLLApi4.dll", EntryPoint = "GetDeviceList", CallingConvention = CallingConvention.StdCall)]
        public static extern void GetDeviceList(ref CAMERA_INFO_LIST dest);
        */
    }
}
