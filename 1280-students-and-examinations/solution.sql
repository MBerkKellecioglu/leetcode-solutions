# Write your MySQL query statement below

With SS as(
    Select *
    From Students
    Join Subjects
)

Select s.student_id, s.student_name, s.subject_name, Count(e.student_id) as attended_exams
From SS s
Left Join Examinations e On (e.student_id = s.student_id AND s.subject_name = e.subject_name)
Group by s.student_id, s.subject_name
Order By s.student_id, s.subject_name