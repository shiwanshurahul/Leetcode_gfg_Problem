# Write your MySQL query statement below

#sare player_id me check krna hai = groupby lagao

-- fraction of players that logged in again on the day after the day they first logged in

-- = each player_id ka check kro ki event_date is consecutive?
-- min(event_date) is first_login

-- SELECT player_id, min(event_date) as first_login
-- from Activity
-- GROUP BY player_id;
-- | player_id | first_login |
-- | --------- | ----------- |
-- | 1         | 2016-03-01  |
-- | 2         | 2017-06-25  |
-- | 3         | 2016-03-02  |

-- ab consecutive date wale dekho = second login
-- = DATE_SUB(event_date, INTERVAL 1 DAY) kro
-- ROUND(count(DISTINCT player_id) aayega subquery se

SELECT ROUND(count(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) as fraction
FROM Activity
WHERE (player_id,  DATE_SUB(event_date, INTERVAL 1 DAY))
IN ( SELECT player_id, min(event_date) as first_login
from Activity
GROUP BY player_id);


--  DATEDIFF(w1.recordDate, w2.recordDate) = 1) but second date ki ni pta






