using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace kadai3
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

        private void button1_Click(object sender, EventArgs e)
        {
            int N = tbInput.Lines.Length;
            double[] data = new double[N];

            for (int i = 0; i < N; i++)
            {
                data[i] = double.Parse(tbInput.Lines[i]);
            }

            double max = 0, min = data[0], ave = 0;

            for (int i = 0; i < N; i++)
            {
                if(data[i] > max)
                {
                    max = data[i];
                }
                if(data[i] < min)
                {
                    min = data[i];
                }
                ave += data[i];
            }
            ave /= N;

            labelMax.Text = max.ToString();
            labelMin.Text = min.ToString();
            labelAve.Text = ave.ToString();
        }
    }
}
