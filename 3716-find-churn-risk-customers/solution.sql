# Write your MySQL query statement below

With latest_event as(
    Select
    user_id,
    event_type,
    plan_name as current_plan,
    monthly_amount as current_monthly_amount,
    Max(monthly_amount) Over (Partition By user_id) as max_historical_amount,
    Sum(Case When event_type = 'downgrade' Then 1 Else 0 End) Over (Partition By user_id) as down,
    ROW_NUMBER() Over(Partition By user_id Order By event_date Desc) as rnk
    From subscription_events 
),

sub_days as(
    Select user_id, DATEDIFF(Max(event_date),Min(event_date)) as days_as_subscriber
    From subscription_events
    Group by user_id
    Having DATEDIFF(Max(event_date), Min(event_date)) >= 60
)

Select le.user_id, current_plan, current_monthly_amount, max_historical_amount, days_as_subscriber
From latest_event le
Join sub_days sd On le.user_id =  sd.user_id
Where rnk = 1 and down >= 1 and current_monthly_amount < max_historical_amount / 2 and event_type != 'cancel'
Order by days_as_subscriber Desc, le.user_id Asc
