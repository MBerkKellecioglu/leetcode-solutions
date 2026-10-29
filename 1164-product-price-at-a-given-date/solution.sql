# Write your MySQL query statement below

With bisect_date as (
    Select product_id, change_date as max_date, new_price as curr_price
    From (
        Select product_id, change_date, ROW_NUMBER() Over(Partition By product_id Order By change_date Desc) as rnk, new_price
        From Products
        Where change_date <= '2019-08-16') as ordered
    Where rnk = 1
)

Select DISTINCT p.product_id, COALESCE(bd.curr_price,10) as price
From Products p
Left Join bisect_date bd On p.product_id = bd.product_id
