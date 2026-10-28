# Write your MySQL query statement below

With Joins as(
    Select user_id as buyer_id, join_date
    From Users 
    Group by user_id
),

order_number as (
    Select o.buyer_id, Sum(Case When Year(order_date) = 2019 Then 1 else 0 End) as orders_in_2019
    From Orders o
    Join Users u On u.user_id = o.buyer_id
    Group by o.buyer_id
)

Select j.buyer_id, join_date, ifnull(orders_in_2019,0) as orders_in_2019
From Joins j
Left Join order_number o On o.buyer_id = j.buyer_id