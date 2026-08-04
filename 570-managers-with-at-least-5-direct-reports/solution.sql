# Write your MySQL query statement below


SELECT e1.name
FROM Employee e1
WHERE id in (
    SELECT e2.managerId
    FROM Employee e2
    GROUP BY e2.managerId
    HAVING COUNT(*) >= 5
)
