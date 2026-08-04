# Write your MySQL query statement below

SELECT d.name as Department, e1.name as Employee, e1.salary as Salary
FROM Employee e1
JOIN Department d ON d.id = e1.departmentId
WHERE (e1.departmentId, e1.salary) in (
    SELECT e2.departmentId, MAX(e2.salary)
    FROM Employee e2
    GROUP BY e2.departmentId
)

