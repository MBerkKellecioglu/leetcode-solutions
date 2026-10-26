# Write your MySQL query statement below

Select project_id, Round(sum(experience_years) / count(*),2) as average_years
From Project p
JOIN Employee e ON p.employee_id = e.employee_id
Group By project_id