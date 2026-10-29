# Write your MySQL query statement below

With all_ids as(
    Select requester_id as id
    From RequestAccepted

    Union

    Select accepter_id as id
    From RequestAccepted
)

Select id, Count(*) as num
From all_ids
Join RequestAccepted On requester_id = id Or accepter_id = id
Group by id
Order by num Desc
Limit 1



