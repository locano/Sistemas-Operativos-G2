namespace ProyectoFinal
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.groupDet = new System.Windows.Forms.GroupBox();
            this.button3 = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txtVeces = new System.Windows.Forms.TextBox();
            this.txtDestino = new System.Windows.Forms.TextBox();
            this.txtOrigen = new System.Windows.Forms.TextBox();
            this.groupIni = new System.Windows.Forms.GroupBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.txtCola = new System.Windows.Forms.TextBox();
            this.txtConsumidores = new System.Windows.Forms.TextBox();
            this.txtProductores = new System.Windows.Forms.TextBox();
            this.dataGridProducers = new System.Windows.Forms.DataGridView();
            this.Thread = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Status = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Regs = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label7 = new System.Windows.Forms.Label();
            this.dataGridCola = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label8 = new System.Windows.Forms.Label();
            this.timerUpdate = new System.Windows.Forms.Timer(this.components);
            this.label9 = new System.Windows.Forms.Label();
            this.dataGridConsumers = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.groupDet.SuspendLayout();
            this.groupIni.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridProducers)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridCola)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridConsumers)).BeginInit();
            this.SuspendLayout();
            // 
            // groupDet
            // 
            this.groupDet.BackColor = System.Drawing.Color.White;
            this.groupDet.Controls.Add(this.button3);
            this.groupDet.Controls.Add(this.label5);
            this.groupDet.Controls.Add(this.button2);
            this.groupDet.Controls.Add(this.label4);
            this.groupDet.Controls.Add(this.label3);
            this.groupDet.Controls.Add(this.txtVeces);
            this.groupDet.Controls.Add(this.txtDestino);
            this.groupDet.Controls.Add(this.txtOrigen);
            this.groupDet.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupDet.Location = new System.Drawing.Point(12, 11);
            this.groupDet.Name = "groupDet";
            this.groupDet.Size = new System.Drawing.Size(737, 125);
            this.groupDet.TabIndex = 17;
            this.groupDet.TabStop = false;
            this.groupDet.Text = "Determinar";
            this.groupDet.Visible = false;
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.button3.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.button3.Image = ((System.Drawing.Image)(resources.GetObject("button3.Image")));
            this.button3.Location = new System.Drawing.Point(518, 19);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(213, 86);
            this.button3.TabIndex = 3;
            this.button3.Text = "Eliminar Registro";
            this.button3.TextImageRelation = System.Windows.Forms.TextImageRelation.TextBeforeImage;
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(16, 88);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(71, 13);
            this.label5.TabIndex = 10;
            this.label5.Text = "No. de veces";
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.MidnightBlue;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.button2.Image = ((System.Drawing.Image)(resources.GetObject("button2.Image")));
            this.button2.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button2.Location = new System.Drawing.Point(243, 20);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(269, 85);
            this.button2.TabIndex = 3;
            this.button2.Text = "Agregar Registro   ";
            this.button2.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(16, 56);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 13);
            this.label4.TabIndex = 9;
            this.label4.Text = "Destino";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(16, 27);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(38, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Origen";
            // 
            // txtVeces
            // 
            this.txtVeces.Location = new System.Drawing.Point(93, 83);
            this.txtVeces.Name = "txtVeces";
            this.txtVeces.Size = new System.Drawing.Size(100, 22);
            this.txtVeces.TabIndex = 2;
            // 
            // txtDestino
            // 
            this.txtDestino.Location = new System.Drawing.Point(93, 51);
            this.txtDestino.Name = "txtDestino";
            this.txtDestino.Size = new System.Drawing.Size(100, 22);
            this.txtDestino.TabIndex = 1;
            // 
            // txtOrigen
            // 
            this.txtOrigen.Location = new System.Drawing.Point(93, 22);
            this.txtOrigen.MaxLength = 3;
            this.txtOrigen.Name = "txtOrigen";
            this.txtOrigen.Size = new System.Drawing.Size(100, 22);
            this.txtOrigen.TabIndex = 0;
            // 
            // groupIni
            // 
            this.groupIni.BackColor = System.Drawing.Color.White;
            this.groupIni.Controls.Add(this.button1);
            this.groupIni.Controls.Add(this.label1);
            this.groupIni.Controls.Add(this.label2);
            this.groupIni.Controls.Add(this.label6);
            this.groupIni.Controls.Add(this.txtCola);
            this.groupIni.Controls.Add(this.txtConsumidores);
            this.groupIni.Controls.Add(this.txtProductores);
            this.groupIni.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupIni.Location = new System.Drawing.Point(12, 12);
            this.groupIni.Name = "groupIni";
            this.groupIni.Size = new System.Drawing.Size(424, 85);
            this.groupIni.TabIndex = 18;
            this.groupIni.TabStop = false;
            this.groupIni.Text = "Inicializar";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 49);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(401, 23);
            this.button1.TabIndex = 11;
            this.button1.Text = "Iniciar";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(276, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 13);
            this.label1.TabIndex = 10;
            this.label1.Text = "Tamaño de cola";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(142, 26);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(73, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "Consumidores";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(12, 26);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(64, 13);
            this.label6.TabIndex = 8;
            this.label6.Text = "Productores";
            // 
            // txtCola
            // 
            this.txtCola.Location = new System.Drawing.Point(366, 21);
            this.txtCola.MaxLength = 2;
            this.txtCola.Name = "txtCola";
            this.txtCola.Size = new System.Drawing.Size(47, 22);
            this.txtCola.TabIndex = 2;
            this.txtCola.Text = "10";
            this.txtCola.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtCola_KeyPress);
            // 
            // txtConsumidores
            // 
            this.txtConsumidores.Location = new System.Drawing.Point(219, 21);
            this.txtConsumidores.MaxLength = 2;
            this.txtConsumidores.Name = "txtConsumidores";
            this.txtConsumidores.Size = new System.Drawing.Size(51, 22);
            this.txtConsumidores.TabIndex = 1;
            this.txtConsumidores.Text = "5";
            this.txtConsumidores.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtConsumidores_KeyPress);
            // 
            // txtProductores
            // 
            this.txtProductores.Location = new System.Drawing.Point(82, 21);
            this.txtProductores.MaxLength = 2;
            this.txtProductores.Name = "txtProductores";
            this.txtProductores.Size = new System.Drawing.Size(54, 22);
            this.txtProductores.TabIndex = 0;
            this.txtProductores.Text = "3";
            this.txtProductores.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtProductores_KeyPress_1);
            // 
            // dataGridProducers
            // 
            this.dataGridProducers.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridProducers.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Thread,
            this.Status,
            this.Regs});
            this.dataGridProducers.Location = new System.Drawing.Point(261, 162);
            this.dataGridProducers.Name = "dataGridProducers";
            this.dataGridProducers.Size = new System.Drawing.Size(482, 138);
            this.dataGridProducers.TabIndex = 19;
            // 
            // Thread
            // 
            this.Thread.HeaderText = "Thread";
            this.Thread.Name = "Thread";
            this.Thread.ReadOnly = true;
            // 
            // Status
            // 
            this.Status.HeaderText = "Status";
            this.Status.Name = "Status";
            this.Status.ReadOnly = true;
            // 
            // Regs
            // 
            this.Regs.HeaderText = "Registros creados";
            this.Regs.Name = "Regs";
            this.Regs.ReadOnly = true;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(261, 146);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(64, 13);
            this.label7.TabIndex = 20;
            this.label7.Text = "Productores";
            // 
            // dataGridCola
            // 
            this.dataGridCola.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridCola.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2});
            this.dataGridCola.Location = new System.Drawing.Point(12, 162);
            this.dataGridCola.Name = "dataGridCola";
            this.dataGridCola.Size = new System.Drawing.Size(243, 310);
            this.dataGridCola.TabIndex = 21;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.HeaderText = "Origen";
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            this.dataGridViewTextBoxColumn1.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.HeaderText = "Destino";
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            this.dataGridViewTextBoxColumn2.ReadOnly = true;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(12, 146);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(28, 13);
            this.label8.TabIndex = 22;
            this.label8.Text = "Cola";
            // 
            // timerUpdate
            // 
            this.timerUpdate.Interval = 50;
            this.timerUpdate.Tick += new System.EventHandler(this.timerUpdate_Tick);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(261, 314);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(73, 13);
            this.label9.TabIndex = 24;
            this.label9.Text = "Consumidores";
            // 
            // dataGridConsumers
            // 
            this.dataGridConsumers.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridConsumers.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4});
            this.dataGridConsumers.Location = new System.Drawing.Point(261, 330);
            this.dataGridConsumers.Name = "dataGridConsumers";
            this.dataGridConsumers.Size = new System.Drawing.Size(482, 142);
            this.dataGridConsumers.TabIndex = 23;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.HeaderText = "Thread";
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            this.dataGridViewTextBoxColumn3.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.HeaderText = "Status";
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            this.dataGridViewTextBoxColumn4.ReadOnly = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.ClientSize = new System.Drawing.Size(761, 486);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.dataGridConsumers);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.dataGridCola);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.dataGridProducers);
            this.Controls.Add(this.groupIni);
            this.Controls.Add(this.groupDet);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupDet.ResumeLayout(false);
            this.groupDet.PerformLayout();
            this.groupIni.ResumeLayout(false);
            this.groupIni.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridProducers)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridCola)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridConsumers)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupDet;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtDestino;
        private System.Windows.Forms.TextBox txtOrigen;
        private System.Windows.Forms.GroupBox groupIni;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtCola;
        private System.Windows.Forms.TextBox txtConsumidores;
        private System.Windows.Forms.TextBox txtProductores;
        private System.Windows.Forms.DataGridView dataGridProducers;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtVeces;
        private System.Windows.Forms.DataGridViewTextBoxColumn Thread;
        private System.Windows.Forms.DataGridViewTextBoxColumn Status;
        private System.Windows.Forms.DataGridViewTextBoxColumn Regs;
        private System.Windows.Forms.DataGridView dataGridCola;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Timer timerUpdate;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.DataGridView dataGridConsumers;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
    }
}

