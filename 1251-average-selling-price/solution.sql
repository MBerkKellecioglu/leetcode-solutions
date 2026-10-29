# Write your MySQL query statement below


Select p.product_id, Round(ifnull(Sum(p.price * units) / Sum(units),0),2) as average_price
From Prices p
Left Join UnitsSold us On us.product_id = p.product_id and purchase_date Between start_date and end_date
Group by p.product_id