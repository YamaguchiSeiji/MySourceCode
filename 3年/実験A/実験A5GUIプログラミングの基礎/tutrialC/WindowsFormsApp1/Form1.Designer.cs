namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.bRun = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.tbYourname = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.IRet = new System.Windows.Forms.Label();
            this.IOut = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // bRun
            // 
            this.bRun.Location = new System.Drawing.Point(44, 66);
            this.bRun.Name = "bRun";
            this.bRun.Size = new System.Drawing.Size(195, 26);
            this.bRun.TabIndex = 0;
            this.bRun.Text = "button1";
            this.bRun.UseVisualStyleBackColor = true;
            this.bRun.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(44, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(39, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "お名前";
            // 
            // tbYourname
            // 
            this.tbYourname.Location = new System.Drawing.Point(102, 24);
            this.tbYourname.Name = "tbYourname";
            this.tbYourname.Size = new System.Drawing.Size(137, 19);
            this.tbYourname.TabIndex = 2;
            this.tbYourname.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(46, 114);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "return";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(46, 151);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(32, 12);
            this.label3.TabIndex = 4;
            this.label3.Text = "printf";
            // 
            // IRet
            // 
            this.IRet.Location = new System.Drawing.Point(117, 110);
            this.IRet.Name = "IRet";
            this.IRet.Size = new System.Drawing.Size(122, 20);
            this.IRet.TabIndex = 5;
            this.IRet.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // IOut
            // 
            this.IOut.Location = new System.Drawing.Point(117, 147);
            this.IOut.Name = "IOut";
            this.IOut.Size = new System.Drawing.Size(122, 20);
            this.IOut.TabIndex = 6;
            this.IOut.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 189);
            this.Controls.Add(this.IOut);
            this.Controls.Add(this.IRet);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.tbYourname);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.bRun);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bRun;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbYourname;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label IRet;
        private System.Windows.Forms.Label IOut;
    }
}

