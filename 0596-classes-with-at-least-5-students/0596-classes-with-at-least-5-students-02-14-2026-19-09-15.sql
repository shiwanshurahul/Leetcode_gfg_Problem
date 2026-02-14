# Write your MySQL query statement below

SELECT class from Courses as C GROUP BY C.class HAVING COUNT(C.student) >= 5;

# m2:
-- SELECT class from Courses as C HAVING COUNT(C.student) >= 5;


