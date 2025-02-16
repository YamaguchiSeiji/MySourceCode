namespace kadai4
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
            this.tbInput = new System.Windows.Forms.TextBox();
            this.tbOutput = new System.Windows.Forms.TextBox();
            this.sortUp = new System.Windows.Forms.Button();
            this.sortDown = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tbInput
            // 
            this.tbInput.Location = new System.Drawing.Point(26, 41);
            this.tbInput.Multiline = true;
            this.tbInput.Name = "tbInput";
            this.tbInput.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbInput.Size = new System.Drawing.Size(143, 221);
            this.tbInput.TabIndex = 0;
            this.tbInput.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // tbOutput
            // 
            this.tbOutput.Location = new System.Drawing.Point(276, 41);
            this.tbOutput.Multiline = true;
            this.tbOutput.Name = "tbOutput";
            this.tbOutput.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbOutput.Size = new System.Drawing.Size(143, 221);
            this.tbOutput.TabIndex = 1;
            this.tbOutput.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // sortUp
            // 
            this.sortUp.Location = new System.Drawing.Point(185, 62);
            this.sortUp.Name = "sortUp";
            this.sortUp.Size = new System.Drawing.Size(75, 66);
            this.sortUp.TabIndex = 2;
            this.sortUp.Text = "昇順ソート";
            this.sortUp.UseVisualStyleBackColor = true;
            this.sortUp.Click += new System.EventHandler(this.sortUp_Click);
            // 
            // sortDown
            // 
            this.sortDown.Location = new System.Drawing.Point(185, 173);
            this.sortDown.Name = "sortDown";
            this.sortDown.Size = new System.Drawing.Size(75, 66);
            this.sortDown.TabIndex = 3;
            this.sortDown.Text = "降順ソート";
            this.sortDown.UseVisualStyleBackColor = true;
            this.sortDown.Click += new System.EventHandler(this.sortDown_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(456, 303);
            this.Controls.Add(this.sortDown);
            this.Controls.Add(this.sortUp);
            this.Controls.Add(this.tbOutput);
            this.Controls.Add(this.tbInput);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbInput;
        private System.Windows.Forms.TextBox tbOutput;
        private System.Windows.Forms.Button sortUp;
        private System.Windows.Forms.Button sortDown;
    }
}

