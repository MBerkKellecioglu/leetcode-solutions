# Write your MySQL query statement below

SELECT
    *,
    CASE
        WHEN abs(t.x - t.y) < t.z and t.x + t.y > t.z and
             abs(t.x - t.z) < t.y and t.x + t.z > t.y and
             abs(t.y - t.z) < t.x and t.y + t.z > t.x THEN 'Yes'
        ELSE 'No'
    END AS triangle
FROM Triangle t