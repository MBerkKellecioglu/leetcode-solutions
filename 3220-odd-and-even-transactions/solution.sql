# Write your MySQL query statement below


Select 
    transaction_date,
    Sum(Case When amount % 2 then amount else 0 End) as odd_sum,
    Sum(Case When amount % 2 = 0 then amount else 0 End) as even_sum
From transactions
Group By transaction_date
Order By transaction_date Asc

