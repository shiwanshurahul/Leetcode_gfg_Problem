# Write your MySQL query statement below
select tweet_id from Tweets as T where LENGTH (T.content) > 15;