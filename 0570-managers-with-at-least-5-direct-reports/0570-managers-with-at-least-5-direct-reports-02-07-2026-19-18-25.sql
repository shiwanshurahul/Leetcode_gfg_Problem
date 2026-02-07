# Write your MySQL query statement below

SELECT name from Employee WHERE id in
(SELECT managerId FROM Employee GROUP BY managerId
HAVING COUNT(managerId)>=5 );

-- If you use an aggregate function (like COUNT) alongside a regular column (like managerId), you must group by that regular column.
-- The columns listed in the SELECT statement that are not part of an aggregate function must be included in the GROUP BY claus
--here you are not using any regular col = no nned to group by that