# Write your MySQL query statement below

Select p.product_id, p.product_name
From Product p
JOIN Sales s ON p.product_id = s.product_id
Group by p.product_id, p.product_name
HAVING MIN(s.sale_date) >= '2019-01-01' and MAX(s.sale_date) <= '2019-03-31'