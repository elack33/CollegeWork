Public Class frmMain

    Private Sub btnCalculate_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCalculate.Click
        Dim objStudent As Student

        ' Create an Instance of the Student Class
        objStudent = New Student

        ' Get the Data from the Form
        GetData(objStudent)

        ' Display the Test Average & Grade
        lblTestAverage.Text = objStudent.TestAverage
        lblGrade.Text = objStudent.TestGrade

        ' Confirm that the Record was Calculated
        MessageBox.Show("Record Calculated", "Calculate Confirmation")

        ' Clear the Form
        ClearForm()

    End Sub

    Private Sub btnExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub

    Private Sub ClearForm()
        ' Clear the Form
        txtFirstName.Clear()
        txtLastName.Clear()
        txtIDNumber.Clear()
        txtGrade0.Clear()
        txtGrade1.Clear()
        txtGrade2.Clear()
        lblTestAverage.Text = String.Empty
        lblGrade.Text = String.Empty

        ' Reset the Focus
        txtLastName.Focus()
    End Sub

    Private Sub GetData(ByVal objStudent As Student)
        ' Get the Data from the Text Boxes and store
        ' in the Object referenced by the Student
        Try
            With objStudent
                .LastName = txtLastName.Text
                .FirstName = txtFirstName.Text
                .IDNumber = txtIDNumber.Text
                .GradeValue(0) = CSng(txtGrade0.Text)
                .GradeValue(1) = CSng(txtGrade1.Text)
                .GradeValue(2) = CSng(txtGrade2.Text)
            End With
        Catch ex As Exception
            MessageBox.Show(ex.Message)
        End Try
    End Sub

End Class
