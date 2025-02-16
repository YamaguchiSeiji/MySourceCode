using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace kadai5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string command = @"C:\WINDOWS\system32\notepad.exe";

            Process p = new Process();
            p.StartInfo.FileName = command;
            p.StartInfo.CreateNoWindow = true;
            p.StartInfo.UseShellExecute = false;

            p.Start();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string command = @"C:\Program Files\Mozilla Firefox\firefox.exe";

            Process p = new Process();
            p.StartInfo.FileName = command;
            p.StartInfo.CreateNoWindow = true;
            p.StartInfo.UseShellExecute = false;

            p.Start();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string command = @"C:\Program Files (x86)\teraterm\ttermpro.exe";

            Process p = new Process();
            p.StartInfo.FileName = command;
            p.StartInfo.CreateNoWindow = true;
            p.StartInfo.UseShellExecute = false;

            p.Start();
        }
    }
}
