# Write your MySQL query statement below

SELECT a1.player_id as player_id, MIN(a1.event_date) as first_login
FROM Activity as a1
GROUP BY a1.player_id