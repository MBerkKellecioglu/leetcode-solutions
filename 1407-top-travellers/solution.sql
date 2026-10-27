# Write your MySQL query statement below

Select name, (Case When Sum(r.distance) > 0 Then Sum(r.distance) Else 0 End) as travelled_distance
From Rides r
Right Join Users u On r.user_id = u.id
Group By r.user_id
Order by travelled_distance Desc, name Asc