# Write your MySQL query statement below

Select customer_id
From customer_transactions
Group by customer_id
Having Count(transaction_id) >= 3 and DATEDIFF(Max(transaction_date),Min(transaction_date)) >= 30 and 
       (Sum(Case When transaction_type = 'refund' Then 1 Else 0 End) / Count(transaction_type)) < 0.2
