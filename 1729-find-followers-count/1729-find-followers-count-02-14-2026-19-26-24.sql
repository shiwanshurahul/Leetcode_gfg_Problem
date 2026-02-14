# Write your MySQL query statement below
#sare user_id ka chahiy = groupby on it

SELECT user_id, count( user_id) as followers_count from Followers
GROUP BY user_id order by user_id asc ;

