Public Class Student
    ' Member Variables
    Private strLastName As String
    Private strFirstName As String
    Private strID As String
    Private sngGrade(2) As Single
    Private J As Integer

    ' Constructor
    Public Sub New()

        Debug.WriteLine("Student Object Created")
        strLastName = String.Empty
        strFirstName = String.Empty
        strID = String.Empty

        For J = 0 To 2
            sngGrade(J) = 0.0
        Next J

    End Sub

    ' LastName Property Procedure
    Public Property LastName() As String
        Get
            Return strLastName
        End Get
        Set(ByVal value As String)
            strLastName = value
        End Set
    End Property

    ' FirstName Property Procedure
    Public Property FirstName() As String
        Get
            Return strFirstName
        End Get
        Set(ByVal value As String)
            strFirstName = value
        End Set
    End Property

    ' IDNumber Property Procedure
    Public Property IDNumber() As String
        Get
            Return strID
        End Get
        Set(ByVal value As String)
            strID = value
        End Set
    End Property

    ' GradeValue Property Procedure
    Public Property GradeValue(ByVal J As Integer) As Single
        Get
            Return sngGrade(J)
        End Get
        Set(ByVal value As Single)
            If value >= 0 And value <= 100 Then
                sngGrade(J) = value
            Else
                Throw New ApplicationException("Test Average must be 0.0 to 100.0")
            End If
        End Set
    End Property

    ' TestAverage Property Procedure
    Public ReadOnly Property TestAverage() As Single
        Get
            Dim sngTotal As Single

            sngTotal = 0
            For J = 0 To 2
                sngTotal += sngGrade(J)
            Next J
            TestAverage = sngTotal / 3

            Return TestAverage
        End Get
    End Property

    ' TestGrade Property Procedure
    Public ReadOnly Property TestGrade() As Char
        Get
            Dim chrGrade As Char
            If TestAverage >= 90.0 Then
                chrGrade = "A"
            ElseIf TestAverage >= 80.0 Then
                chrGrade = "B"
            ElseIf TestAverage >= 70.0 Then
                chrGrade = "C"
            ElseIf TestAverage >= 60.0 Then
                chrGrade = "D"
            Else
                chrGrade = "F"
            End If
            Return chrGrade
        End Get
    End Property

    ' Finalizer
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
        Debug.WriteLine("Student Object Destroyed")
    End Sub
End Class
