using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace AppWPF
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {

        }

        private void Windows_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {

        }

        private void bt1_Click(object sender, RoutedEventArgs e)
        {
            int a = DLLApi.func1(10);
            MessageBox.Show(a+"", "func1");
        }

        private void bt2_Click(object sender, RoutedEventArgs e)
        {
            float f1 = 10.1f;
            float f2 = 0;
            DLLApi.func2(f1, ref f2);
            MessageBox.Show("f1: " + f1 + ", f2: " + f2, "func2");
        }

        private void bt3_Click(object sender, RoutedEventArgs e)
        {
            int len = 3;
            float[] f1 = new float[len];
            float[] f2 = new float[len];

            for(int i = 0; i < len; i++)
            {
                f1[i] = 1.1f * i;
            }
            DLLApi.func3(f1, f2, len);

            String msg = "F1: ";
            foreach(float f in f1)
            {
                msg = msg + f + ", ";
            }
            msg += "F2: ";
            foreach (float f in f2)
            {
                msg = msg + f + ", ";
            }

            MessageBox.Show(msg,"func3");
        }

        private void bt4_1_Click(object sender, RoutedEventArgs e)
        {
            byte[] src = Encoding.ASCII.GetBytes("byte from C#");
            byte[] dest = new byte[10];

            DLLApi.func4_byte(src, dest, dest.Length);

            String str_src = Encoding.ASCII.GetString(src);
            String str_dest = Encoding.ASCII.GetString(dest);

            MessageBox.Show("SRC: " + str_src+ "\n" + "DEST: " + str_dest, "func4_byte");
        }

        private void bt4_2_Click(object sender, RoutedEventArgs e)
        {
            String src = "Marshal form C#";
            StringBuilder dest = new StringBuilder(10);

            DLLApi.func4_marshal(src, dest, dest.Capacity);

            MessageBox.Show("SRC: " + src + "\n" + "DEST: " + dest.ToString(), "func4_marshal");
        }

        private void bt5_Click(object sender, RoutedEventArgs e)
        {
            DLLApi.param p1 = new DLLApi.param();
            DLLApi.param p2 = new DLLApi.param();

            p1.p1 = 10;
            p1.p2 = 0.1f;

            DLLApi.func5(p1, ref p2);

            MessageBox.Show("SRC: " + p1.p1 + ", " + p1.p2 + "\nDEST: " + p2.p1 + ", " + p2.p2, "func5");
        }
    }
}
