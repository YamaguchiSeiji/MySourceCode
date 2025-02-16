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

namespace kadai6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void bRun_Click(object sender, EventArgs e)
        {
            string command = @".\searchbook.exe";

            Process p = new Process();
            p.StartInfo.FileName = command;
            p.StartInfo.Arguments = tbKeyword.Text;
            p.StartInfo.CreateNoWindow = true;
            p.StartInfo.UseShellExecute = false;
            p.StartInfo.RedirectStandardOutput = true;
            p.StartInfo.StandardOutputEncoding = Encoding.UTF8;

            p.Start();
            p.WaitForExit();

            int ret = p.ExitCode;
            string output = p.StandardOutput.ReadToEnd();

            label.Text = output;
        }
    }
}
