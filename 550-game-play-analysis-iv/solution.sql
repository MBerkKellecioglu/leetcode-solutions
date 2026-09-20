# Write your MySQL query statement below

SELECT ROUND(COUNT(*) * 1.0 / (SELECT COUNT(DISTINCT player_id) FROM Activity),2) as fraction
FROM (
    SELECT player_id, MIN(event_date) as event_date
    FROM Activity
    GROUP BY player_id) as min_dates
JOIN Activity a1 ON a1.player_id = min_dates.player_id AND DATEDIFF(a1.event_date,min_dates.event_date) = 1
