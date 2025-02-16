namespace kadai6
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
            this.bRun1 = new System.Windows.Forms.Button();
            this.tbKeyword = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // bRun1
            // 
            this.bRun1.Location = new System.Drawing.Point(39, 105);
            this.bRun1.Name = "bRun1";
            this.bRun1.Size = new System.Drawing.Size(291, 25);
            this.bRun1.TabIndex = 0;
            this.bRun1.Text = "検索";
            this.bRun1.UseVisualStyleBackColor = true;
            this.bRun1.Click += new System.EventHandler(this.bRun_Click);
            // 
            // tbKeyword
            // 
            this.tbKeyword.Location = new System.Drawing.Point(160, 45);
            this.tbKeyword.Name = "tbKeyword";
            this.tbKeyword.Size = new System.Drawing.Size(170, 19);
            this.tbKeyword.TabIndex = 1;
            this.tbKeyword.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label1
            // 
            this.label1.Font = new System.Drawing.Font("MS UI Gothic", 15F);
            this.label1.Location = new System.Drawing.Point(35, 41);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(90, 27);
            this.label1.TabIndex = 2;
            this.label1.Text = "キーワード";
            // 
            // label
            // 
            this.label.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label.Location = new System.Drawing.Point(39, 159);
            this.label.Name = "label";
            this.label.Size = new System.Drawing.Size(291, 123);
            this.label.TabIndex = 3;
            this.label.Click += new System.EventHandler(this.label2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(372, 308);
            this.Controls.Add(this.label);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbKeyword);
            this.Controls.Add(this.bRun1);
            this.Name = "Form1";
            this.Text = "在庫検索システム";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bRun1;
        private System.Windows.Forms.TextBox tbKeyword;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label;
    }
}

