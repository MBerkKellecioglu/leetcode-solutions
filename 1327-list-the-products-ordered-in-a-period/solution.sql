# Write your MySQL query statement below

Select product_name, SUM(unit) as unit
From Products p
Join Orders o On p.product_id = o.product_id
WHERE order_date >= '2020-02-01' and order_date <= '2020-02-29'
Group By o.product_id
Having SUM(unit) >= 100