# Write your MySQL query statement below
 

Select 
    stock_name,
    (Sum(Case When operation = 'Sell' Then price else 0 End) - Sum(Case When operation = 'Buy' Then price else 0 End)) as capital_gain_loss
From Stocks
Group By stock_name
