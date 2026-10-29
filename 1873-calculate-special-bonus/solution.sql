# Write your MySQL query statement below

Select employee_id, (Case When (employee_id % 2) and name Not Like 'M%' Then salary Else 0 END) as bonus
From Employees
Order By employee_id
