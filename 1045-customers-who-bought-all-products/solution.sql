# Write your MySQL query statement below

SELECT customer_id
From Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*)
    FROM Product)