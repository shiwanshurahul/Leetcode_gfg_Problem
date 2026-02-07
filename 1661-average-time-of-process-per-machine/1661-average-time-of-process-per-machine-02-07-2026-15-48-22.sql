# Write your MySQL query statement below


-- The SQL GROUP BY clause is used to arrange identical data into groups based on one or more columns. It is commonly used with aggregate functions like COUNT(), SUM(), AVG(), MAX(), and MIN() to perform calculations on each group of data. -> same as pandas 
#groupby usiko kroge jisme multiple group ho primary key pe v kr skte  

-- If you use an aggregate function (like AVG) alongside a regular column (like machine_id), you must group by that regular column.
-- The columns listed in the SELECT statement that are not part of an aggregate function must be included in the GROUP BY claus
-- Without a GROUP BY clause here, the database doesn't know how to associate the single "AVG" with the multiple individual "machine_id."

#primary key hai machine_id, process_id and activity_type
# = INNER JOIN krdo khud se such that 'start' and 'end' amne samne aaye
-- This allows us to pair the start and end activities for each machine.

-- | machine_id | activity_type | activity_type |
-- | ---------- | ------------- | ------------- |
-- | 0          | start         | end           |
-- | 1          | start         | end           |
-- | 2          | start         | end           |

SELECT A1.machine_id, ROUND(AVG(A2.timestamp - A1.timestamp),3) as
processing_time FROM Activity as A1 INNER JOIN
Activity as A2 
ON A1.process_id = A2.process_id AND
A1.machine_id = A2.machine_id AND
A1.activity_type='start' AND A2.activity_type='end'
GROUP BY A1.machine_id;  #warna sql error ->




