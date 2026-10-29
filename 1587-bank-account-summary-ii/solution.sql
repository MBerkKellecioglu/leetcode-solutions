# Write your MySQL query statement below

Select name, Sum(amount) as balance
From Users u
Join Transactions t On t.account = u.account 
Group By t.account
Having Sum(amount) > 10000
