# Write your MySQL query statement below

WITH red_sellers AS (SELECT o.sales_id
FROM Orders o
JOIN Company c ON o.com_id = c.com_id and c.name = 'RED')

SELECT s.name
FROM SalesPerson s
WHERE s.sales_id NOT IN (SELECT sales_id from red_sellers)