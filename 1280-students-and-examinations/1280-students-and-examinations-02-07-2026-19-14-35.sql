# Write your MySQL query statement below

-- 3 table hai
-- Each student from the Students table takes every course from the Subjects table = cross join kro dono ko
-- taki sare rows,cols consider kro

-- CROSS JOIN (Cartesian product) is like making every possible pair of rows from two tables.
-- isme ON ni likhna hota ki kis ke basi pe kr rhe
-- as it takes evry pairing (both in SQL and pandas)

-- - The SQL GROUP BY clause is used to arrange identical data into groups based on one or more columns. It is commonly used with aggregate functions like COUNT(), SUM(), AVG(), MAX(), and MIN() to perform calculations on each group of data. -> same as pandas 
#groupby usiko kroge jisme multiple group ho primary key pe v kr skte  

-- If you use an aggregate function (like COUNT) alongside a regular column (like student_id), you must group by that regular column.
-- The columns listed in the SELECT statement that are not part of an aggregate function must be included in the GROUP BY claus
-- Without a GROUP BY clause here, the database doesn't know how to associate the single "COUNT" with the multiple individual "student_id."

-- SELECT name from Employee WHERE id in
-- (SELECT managerId FROM Employee GROUP BY managerId
-- HAVING COUNT(managerId)>=5 );  -> correct hai ye

SELECT S.student_id, S.student_name, Sub.subject_name,
COUNT(E.subject_name) as attended_exams
FROM Students as S 
CROSS JOIN Subjects as Sub
LEFT JOIN Examinations E
ON S.student_id = E.student_id AND
Sub.subject_name = E.subject_name
GROUP BY S.student_id, S.student_name, Sub.subject_name
ORDER BY S.Student_id, Sub.subject_name;

