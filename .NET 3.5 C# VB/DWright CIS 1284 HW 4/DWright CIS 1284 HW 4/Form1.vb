Public Class Form1

    Dim sngMaximumAmount As Single = 100
    Dim sngIncrementAmount As Single = 1


    Private Sub btnExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub

    Private Sub btnClear_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnClear.Click

        'Clear form

        txtUSMaximumCurrency.Text = 100
        txtIncrement.Text = 5

        lstCurrencyTypes.SelectedIndex = -1
        lstResults.Items.Clear()
        txtUSMaximumCurrency.Focus()

    End Sub



    Private Sub btnConvert_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnConvert.Click

        'declare variables

        Dim Start, Finish, Interval As Single
        Dim sngCStart As Single = 0
        Dim sngCEnd As Single = 0

        If lstCurrencyTypes.SelectedIndex = -1 Then
            MessageBox.Show("Please choose a currency type to convert to!", "No Data", MessageBoxButtons.OK, MessageBoxIcon.Error)
            lstCurrencyTypes.Focus()
            Exit Sub
        End If

        lstResults.Items.Clear()

        Start = 0
        Finish = Val(txtUSMaximumCurrency.Text)
        Interval = Val(txtIncrement.Text)

        If lstCurrencyTypes.SelectedIndex = 0 Then
            lstResults.Items.Add("Us Dollars            European Euro")

            For sngCStart = Start To Finish Step Interval
                sngCEnd = sngCStart * 0.08155
                lstResults.Items.Add(FormatNumber(sngCStart) & "                      " & FormatNumber(sngCEnd))
            Next

        ElseIf lstCurrencyTypes.SelectedIndex = 1 Then
            lstResults.Items.Add("Us Dollars            Japan Yen")

            For sngCStart = Start To Finish Step Interval
                sngCEnd = sngCStart * 110.83
                lstResults.Items.Add(FormatNumber(sngCStart) & "                        " & FormatNumber(sngCEnd))
            Next

        ElseIf lstCurrencyTypes.SelectedIndex = 2 Then
            lstResults.Items.Add("Us Dollars            Australia Dollars")

            For sngCStart = Start To Finish Step Interval
                sngCEnd = sngCStart * 1.4021
                lstResults.Items.Add(FormatNumber(sngCStart) & "                         " & FormatNumber(sngCEnd))
            Next

        ElseIf lstCurrencyTypes.SelectedIndex = 3 Then
            lstResults.Items.Add("Us Dollars            India Rupees")

            For sngCStart = Start To Finish Step Interval
                sngCEnd = sngCStart * 45.845
                lstResults.Items.Add(FormatNumber(sngCStart) & "                          " & FormatNumber(sngCEnd))
            Next

        ElseIf lstCurrencyTypes.SelectedIndex = 4 Then
            lstResults.Items.Add("Us Dollars            Mexico Pesos")

            For sngCStart = Start To Finish Step Interval
                sngCEnd = sngCStart * 11.3955
                lstResults.Items.Add(FormatNumber(sngCStart) & "                         " & FormatNumber(sngCEnd))
            Next

        ElseIf lstCurrencyTypes.SelectedIndex = 5 Then
            lstResults.Items.Add("Us Dollars            Russia Rubles")

            For sngCStart = Start To Finish Step Interval
                sngCEnd = sngCStart * 29.21
                lstResults.Items.Add(FormatNumber(sngCStart) & "                         " & FormatNumber(sngCEnd))
            Next

        ElseIf lstCurrencyTypes.SelectedIndex = 6 Then
            lstResults.Items.Add("Us Dollars            Englang Pounds")

            For sngCStart = Start To Finish Step Interval
                sngCEnd = sngCStart * 0.5568
                lstResults.Items.Add(FormatNumber(sngCStart) & "          " & FormatNumber(sngCEnd))
            Next

        End If


    End Sub


    Private Sub txtUSMaximumCurrency_Validating(ByVal sender As Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles txtUSMaximumCurrency.Validating

        'verify max currency amount is a number greater than zero

        sngMaximumAmount = Val(txtUSMaximumCurrency.Text)

        If txtUSMaximumCurrency.Text = "" Then

            MessageBox.Show("Please enter a maxiumum number of dollars to convert!", "No Data", MessageBoxButtons.OK, MessageBoxIcon.Error)
            e.Cancel = True

        ElseIf IsNumeric(txtUSMaximumCurrency.Text) = False Then

            MessageBox.Show("Please enter a maxiumum number of dollars to convert!", "Non Numeric Entry", MessageBoxButtons.OK, MessageBoxIcon.Error)
            txtUSMaximumCurrency.Clear()
            e.Cancel = True

        ElseIf sngMaximumAmount < 0 Then

            MessageBox.Show("Please enter a number greater then zero!", "Out of Range", MessageBoxButtons.OK, MessageBoxIcon.Error)
            txtUSMaximumCurrency.Clear()
            e.Cancel = True


        Else
            e.Cancel = False

        End If

    End Sub

  

    Private Sub txtIncrement_Validating(ByVal sender As Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles txtIncrement.Validating

        sngIncrementAmount = Val(txtIncrement.Text)


        If txtIncrement.Text = "" Then

            MessageBox.Show("Please enter a number to increment the currency by!", "No Data", MessageBoxButtons.OK, MessageBoxIcon.Error)
            e.Cancel = True

        ElseIf IsNumeric(txtIncrement.Text) = False Then

            MessageBox.Show("Please enter a number to increment the currency by!", "Non Numeric", MessageBoxButtons.OK, MessageBoxIcon.Error)
            txtIncrement.Clear()
            e.Cancel = True

        ElseIf sngIncrementAmount < 0 Then

            MessageBox.Show("Please enter a number greater then zero!", "Out of Range", MessageBoxButtons.OK, MessageBoxIcon.Error)
            txtIncrement.Clear()
            e.Cancel = True

        Else
            e.Cancel = False

        End If

    End Sub

    Private Sub lstCurrencyTypes_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lstCurrencyTypes.SelectedIndexChanged

        lstResults.Items.Clear()

    End Sub
End Class
