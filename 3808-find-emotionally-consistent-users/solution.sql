# Write your MySQL query statement below

With sixty as(
    Select r.user_id, r.reaction as dominant_reaction, Round(Count(*) / total_count,2) as reaction_ratio
    From reactions r 
    Join (
        Select user_id, Count(*) as total_count
        From reactions
        Group By user_id
    ) as tr On r.user_id = tr.user_id 
    Group By r.user_id, r.reaction, tr.total_count
    Having Count(*) / total_count >= 0.6 and total_count >= 5
)

Select user_id, dominant_reaction, reaction_ratio
From sixty
Order By reaction_ratio Desc, user_id Asc
