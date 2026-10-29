# Write your MySQL query statement below

With cumulative as(
    Select person_name, Sum(weight) Over(Order by turn) as total_weight
    From Queue 
)

Select person_name
From cumulative
Where total_weight <= 1000
Order By total_weight Desc
Limit 1
