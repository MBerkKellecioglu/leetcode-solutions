# Write your MySQL query statement below

Select activity_date as day, COUNT(DISTINCT user_id) as active_users
From Activity
Group By activity_date
Having activity_date >= '2019-06-28' and activity_date <= '2019-07-27'