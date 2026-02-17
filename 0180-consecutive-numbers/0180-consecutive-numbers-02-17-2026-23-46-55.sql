# Write your MySQL query statement below

-- numbers that appear at least three times consecutively.

select DISTINCT l1.num as ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3
WHERE l1.num = l2.num AND l2.num = l3.num
AND l1.id = l2.id -1 AND l2.id = l3.id -1;

