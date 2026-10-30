# Write your MySQL query statement below

Select 
    user_id, 
    Round(Avg(Case When activity_type = 'free_trial' Then activity_duration else null End),2) as trial_avg_duration, 
    Round(Avg(Case When activity_type = 'paid' Then activity_duration else null End),2) as paid_avg_duration
From UserActivity 
Group By user_id
Having Sum(activity_type = 'paid') > 0 and Sum(activity_type = 'free_trial') > 0
Order By user_id Asc
