# Write your MySQL query statement below

Select 'Low Salary' as category, Count(*) as accounts_count
From Accounts
Where income < 20000

Union

Select 'Average Salary' as category, Count(*) as accounts_count
From Accounts
Where 20000 <= income and income <= 50000

Union

Select 'High Salary' as category, Count(*) as accounts_count
From Accounts
Where income > 50000



