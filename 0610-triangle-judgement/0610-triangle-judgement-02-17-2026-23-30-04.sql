# Write your MySQL query statement below

#len of any 2 sides > single side = triangle

SELECT x, y, z, if(x+y > z AND x+z>y AND y+z > x, "Yes", "No")
as triangle from Triangle;