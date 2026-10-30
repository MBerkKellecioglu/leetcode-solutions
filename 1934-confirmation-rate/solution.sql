# Write your MySQL query statement below

Select s.user_id as user_id, Round(Coalesce(Sum(Case When action = 'confirmed' Then 1 Else 0 End) / Count(action),0),2) as confirmation_rate
From Signups s
Left Join Confirmations c On s.user_id = c.user_id
Group By s.user_id