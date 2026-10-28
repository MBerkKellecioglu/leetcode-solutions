# Write your MySQL query statement below

# Regex in SQL requires two backslashes which is crazy to me

Select *
From Users
Where email REGEXP "^[A-Za-z0-9_]+@[A-Za-z]+\\.com$"
Order by user_id Asc