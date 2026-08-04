# Write your MySQL query statement below

SELECT
    t1.id,
    CASE
        WHEN p_id IS NULL THEN "Root"
        WHEN EXISTS (
            SELECT 1
            FROM Tree t2
            WHERE t1.id = t2.p_id
        ) THEN "Inner"
        ELSE "Leaf"
    END AS type
FROM Tree t1