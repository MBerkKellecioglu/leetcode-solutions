# Write your MySQL query statement below

Select unique_id, name
From Employees e
Left Join EmployeeUNI eu On e.id = eu.id