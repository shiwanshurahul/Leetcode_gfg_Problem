# Write your MySQL query statement below
SELECT unique_id, name from Employees as E 
LEFT JOIN EmployeeUNI AS EU on E.id = EU.id;
