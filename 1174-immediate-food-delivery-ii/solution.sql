# Write your MySQL query statement below

With first_orders as(
    Select customer_id, order_date, ROW_NUMBER() Over(Partition By customer_id Order By order_date) as rnk, customer_pref_delivery_date 
    From Delivery
)

Select Round(AVG(order_date = customer_pref_delivery_date) * 100, 2) as immediate_percentage
From first_orders
Where rnk = 1

