# Write your MySQL query statement below


With minimum as(
    Select product_id, Min(s.year) as first_year
    From Sales s
    Group by product_id
)

Select s.product_id, first_year, s.quantity, s.price
From Sales s
Join minimum m On s.product_id = m.product_id and s.year = first_year

