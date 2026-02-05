# Write your MySQL query statement below
#khud se join krdo to compare it to the day before

-- Datediff is used to calculate the difference between two date or time values, returning the result as an integer in a specified unit of time

select W1.id from Weather as W1 INNER JOIN
Weather as W2 on DATEDIFF(w1.recordDate, w2.recordDate) = 1
where w1.temperature > w2.temperature;