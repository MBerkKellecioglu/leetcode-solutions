# Write your MySQL query statement below


With counts as(
    Select user_id, Count(*) as user_count
    From Users
)

Select contest_id, Round(Count(*) / user_count * 100,2) as percentage
From Register r
Join counts c
Group By contest_id
Order By percentage Desc, contest_id Asc