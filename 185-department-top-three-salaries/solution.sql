# Write your MySQL query statement below

Select d.name as Department, e1.name as Employee, e1.salary as Salary
From Employee e1
JOIN Department d ON e1.departmentID = d.id
WHERE (
    Select COUNT(DISTINCT e2.salary)
    From Employee e2
    WHERE e2.salary > e1.salary and e2.departmentID = e1.departmentID
) < 3