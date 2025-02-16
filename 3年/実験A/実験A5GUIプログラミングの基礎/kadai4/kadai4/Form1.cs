using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace kadai4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void sortUp_Click(object sender, EventArgs e)
        {
            int N = tbInput.Lines.Length;
            double[] data = new double[N];

            int i = 0;

            for (i = 0; i < N; i++)
            {
                data[i] = double.Parse(tbInput.Lines[i]);
            }

            double tmp;

            i = 0;
            while(i < N-1)
            {
                if(data[i] > data[i+1])
                {
                    tmp = data[i];
                    data[i] = data[i+1];
                    data[i+1] = tmp;
                    i = 0;
                } else
                {
                    i++;
                }
            }

            tbOutput.Text = "";
            for(i = 0; i < N; i++)
            {
                tbOutput.Text = tbOutput.Text + data[i].ToString("###.###\r\n");
            }
        }

        private void sortDown_Click(object sender, EventArgs e)
        {
            int N = tbInput.Lines.Length;
            double[] data = new double[N];

            int i = 0;

            for (i = 0; i < N; i++)
            {
                data[i] = double.Parse(tbInput.Lines[i]);
            }

            double tmp;

            i = 0;
            while (i < N - 1)
            {
                if (data[i] < data[i + 1])
                {
                    tmp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = tmp;
                    i = 0;
                }
                else
                {
                    i++;
                }
            }

            tbOutput.Text = "";
            for (i = 0; i < N; i++)
            {
                tbOutput.Text = tbOutput.Text + data[i].ToString("###.###\r\n");
            }
        }
    }
}
