# Write your MySQL query statement below

Select actor_id, director_id
From ActorDirector
Group by actor_id, director_id
Having COUNT(*) >= 3