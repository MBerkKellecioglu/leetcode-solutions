# Write your MySQL query statement below

With greatest_user as(
    Select name
    From MovieRating mr
    Join Users u On u.user_id = mr.user_id
    Group by mr.user_id
    Order by Count(*) Desc, u.name Asc
    Limit 1),

highest_average as(
    Select title
    From MovieRating mr
    Join Movies m On m.movie_id = mr.movie_id
    Where created_at Between '2020-02-01' AND '2020-02-29'
    Group by mr.movie_id
    Order by (Sum(rating) / Count(*)) Desc, m.title Asc
    Limit 1)

Select title as results
From highest_average
UNION ALL
Select *
From greatest_user

