# Write your MySQL query statement below

-- contest_id pe group by

Select contest_id, ROUND( COUNT( DISTINCT user_id)*100 / (select count(user_id) from Users), 2) as percentage 
from Register GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC; 



