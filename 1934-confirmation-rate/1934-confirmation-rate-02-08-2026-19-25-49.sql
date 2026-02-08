# Write your MySQL query statement below

#get the confirmation rate of each user
#use left join as Signups ke sare user_id ka confiramtion_rate chahy
#and so groupby kro S.user_id pe

#SUM(C.action='confirmed')/COUNT(c.action) -> quest

-- return the specified value IF the expression is NULL, otherwise return the expression:


SELECT S.user_id, IFNULL(ROUND( SUM(C.action='confirmed')/COUNT(c.action), 2), 0.00) as confirmation_rate from Signups as S
LEFT JOIN Confirmations as C
on S.user_id = C.user_id
GROUP BY S.user_id;
