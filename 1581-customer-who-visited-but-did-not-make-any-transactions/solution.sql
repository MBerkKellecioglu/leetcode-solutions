# Write your MySQL query statement below

Select customer_id, Count(*) as count_no_trans
From Visits v
Where v.visit_id Not In(Select visit_id From Transactions t )
Group By customer_id