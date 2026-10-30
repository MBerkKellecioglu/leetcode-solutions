# Write your MySQL query statement below

With names as (
    Select employee_id, name
    From Employees
    Group by employee_id
)

Select reports_to as employee_id, (Select name From names Where employee_id = reports_to) as name, Count(*) as reports_count, Round(Avg(age)) as average_age
From Employees
Where reports_to is not Null
Group By reports_to
Order by employee_id
