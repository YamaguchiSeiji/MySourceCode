using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace kadai1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            cul();
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                cul();
            }
        }
        private void tbOperator_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                cul();
            }
        }

        private void textBox2_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                cul();
            }
        }

        private void cul()
        {
            if (textBox1.Text == "" || textBox2.Text == "" || tbOperator.Text == "")
            {
                MessageBox.Show("Error!");
            }
            else
            {

                float inputNum1, inputNum2, answer = 0;
                inputNum1 = float.Parse(textBox1.Text);
                inputNum2 = float.Parse(textBox2.Text);

                string op = tbOperator.Text;

                if (op == "+")
                {
                    answer = inputNum1 + inputNum2;
                }
                else if (op == "-")
                {
                    answer = inputNum1 - inputNum2;
                }
                else if (op == "*")
                {
                    answer = inputNum1 * inputNum2;
                }
                else if (op == "/")
                {
                    answer = inputNum1 / inputNum2;
                }

                label1.Text = answer.ToString();
            }
        }

        
    }
}
