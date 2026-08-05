# Write your MySQL query statement below
 
SELECT 
    s.score,
    DENSE_RANK() OVER (ORDER BY s.score DESC) as "rank"
FROM Scores s