# Write your MySQL query statement below

#you didn't got any bonus. remember

SELECT name, bonus from Employee as E LEFT JOIN
Bonus as B ON E.empid = B.empid
where B.bonus < 1000 OR B.bonus is NULL; 