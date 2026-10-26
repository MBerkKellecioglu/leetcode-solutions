# Write your MySQL query statement below

With Endorsment As (
    Select visited_on, sum(amount) as amount
    From Customer
    Group by visited_on
),

Expand as (
    Select 
        visited_on,
        Sum(amount) Over(
            Order By visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) as total_amount,
        Round(
            Avg(amount) Over(
                Order By visited_on
                Rows Between 6 Preceding And Current Row
            ),2) as average_amount,

        Row_Number() Over(Order by visited_on) as ordered
    From Endorsment
)

Select visited_on, total_amount as amount, average_amount
From Expand
Where ordered >= 7
Order By visited_on