# Write your MySQL query statement below

With first_positive as(
    Select patient_id, Min(test_date) as p_date
    From covid_tests
    Where result = 'Positive'
    Group By patient_id
),

recovery as (
    Select c.patient_id, DATEDIFF(Min(test_date), p_date) as recovery_time
    From covid_tests c
    Join first_positive fp On fp.patient_id = c.patient_id and c.test_date > p_date
    Where result = 'Negative' 
    Group by c.patient_id
)

Select p.patient_id, patient_name, age, recovery_time
From recovery r
Join patients p On r.patient_id = p.patient_id
Order by recovery_time Asc, patient_name Asc

