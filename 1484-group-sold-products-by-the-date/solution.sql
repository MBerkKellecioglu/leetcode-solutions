# Write your MySQL query statement below

Select sell_date, Count(Distinct product) as num_sold, GROUP_CONCAT(DISTINCT product) as products
From Activities
Group By sell_date
Order by sell_date
