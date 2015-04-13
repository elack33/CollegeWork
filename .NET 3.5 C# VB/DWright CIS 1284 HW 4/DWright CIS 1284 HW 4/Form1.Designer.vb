<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label
        Me.txtUSMaximumCurrency = New System.Windows.Forms.TextBox
        Me.lstCurrencyTypes = New System.Windows.Forms.ListBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.btnConvert = New System.Windows.Forms.Button
        Me.btnClear = New System.Windows.Forms.Button
        Me.btnExit = New System.Windows.Forms.Button
        Me.lstResults = New System.Windows.Forms.ListBox
        Me.txtIncrement = New System.Windows.Forms.TextBox
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 35)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(264, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Enter the Maximum amount of US Currency to convert:"
        '
        'txtUSMaximumCurrency
        '
        Me.txtUSMaximumCurrency.Location = New System.Drawing.Point(302, 28)
        Me.txtUSMaximumCurrency.Name = "txtUSMaximumCurrency"
        Me.txtUSMaximumCurrency.Size = New System.Drawing.Size(100, 20)
        Me.txtUSMaximumCurrency.TabIndex = 1
        Me.txtUSMaximumCurrency.Text = "100"
        '
        'lstCurrencyTypes
        '
        Me.lstCurrencyTypes.FormattingEnabled = True
        Me.lstCurrencyTypes.Items.AddRange(New Object() {"Europe Euro", "Japan Yen", "Austrailia Dollar", "India Rupee", "Mexico Peso", "Russia Ruble", "England Pound"})
        Me.lstCurrencyTypes.Location = New System.Drawing.Point(302, 135)
        Me.lstCurrencyTypes.Name = "lstCurrencyTypes"
        Me.lstCurrencyTypes.Size = New System.Drawing.Size(100, 95)
        Me.lstCurrencyTypes.TabIndex = 2
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(99, 80)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(177, 13)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Choose the amount to increment by:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(65, 135)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(211, 13)
        Me.Label3.TabIndex = 5
        Me.Label3.Text = "Choose the country/currency to convert to:"
        '
        'btnConvert
        '
        Me.btnConvert.Location = New System.Drawing.Point(327, 246)
        Me.btnConvert.Name = "btnConvert"
        Me.btnConvert.Size = New System.Drawing.Size(75, 23)
        Me.btnConvert.TabIndex = 6
        Me.btnConvert.Text = "Convert"
        Me.btnConvert.UseVisualStyleBackColor = True
        '
        'btnClear
        '
        Me.btnClear.Location = New System.Drawing.Point(68, 246)
        Me.btnClear.Name = "btnClear"
        Me.btnClear.Size = New System.Drawing.Size(75, 23)
        Me.btnClear.TabIndex = 7
        Me.btnClear.Text = "Clear"
        Me.btnClear.UseVisualStyleBackColor = True
        '
        'btnExit
        '
        Me.btnExit.Location = New System.Drawing.Point(186, 246)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(75, 23)
        Me.btnExit.TabIndex = 8
        Me.btnExit.Text = "E&xit"
        Me.btnExit.UseVisualStyleBackColor = True
        '
        'lstResults
        '
        Me.lstResults.FormattingEnabled = True
        Me.lstResults.Location = New System.Drawing.Point(44, 293)
        Me.lstResults.Name = "lstResults"
        Me.lstResults.Size = New System.Drawing.Size(358, 238)
        Me.lstResults.TabIndex = 9
        '
        'txtIncrement
        '
        Me.txtIncrement.Location = New System.Drawing.Point(302, 80)
        Me.txtIncrement.Name = "txtIncrement"
        Me.txtIncrement.Size = New System.Drawing.Size(100, 20)
        Me.txtIncrement.TabIndex = 11
        Me.txtIncrement.Text = "5"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(445, 570)
        Me.Controls.Add(Me.txtIncrement)
        Me.Controls.Add(Me.lstResults)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.btnClear)
        Me.Controls.Add(Me.btnConvert)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.lstCurrencyTypes)
        Me.Controls.Add(Me.txtUSMaximumCurrency)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Currency Converter"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents txtUSMaximumCurrency As System.Windows.Forms.TextBox
    Friend WithEvents lstCurrencyTypes As System.Windows.Forms.ListBox
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents btnConvert As System.Windows.Forms.Button
    Friend WithEvents btnClear As System.Windows.Forms.Button
    Friend WithEvents btnExit As System.Windows.Forms.Button
    Friend WithEvents lstResults As System.Windows.Forms.ListBox
    Friend WithEvents txtIncrement As System.Windows.Forms.TextBox

End Class
