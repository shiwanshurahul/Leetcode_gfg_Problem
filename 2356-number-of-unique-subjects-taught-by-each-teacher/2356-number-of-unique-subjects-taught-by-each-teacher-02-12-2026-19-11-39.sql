# Write your MySQL query statement below

#sare teacher chahiy = groupby on teacher_id
-- number of unique subjects each teacher teaches in the university.

SELECT teacher_id, COUNT(DISTINCT (subject_id)) as cnt
from Teacher GROUP BY teacher_id;




