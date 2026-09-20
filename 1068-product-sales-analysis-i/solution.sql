# Write your MySQL query statement below


Select product_name, year, price
From Sales s, Product p
Where s.product_id = p.product_id
Group by sale_id,year