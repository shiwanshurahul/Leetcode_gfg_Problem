# Write your MySQL query statement below

#odd no id that is not boring

SELECT * from Cinema as C
where C.id %2 = 1 AND C.description !='boring'
ORDER BY C.rating DESC;
