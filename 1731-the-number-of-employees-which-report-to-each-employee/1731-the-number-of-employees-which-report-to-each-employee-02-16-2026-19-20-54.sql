# Write your MySQL query statement below

-- manager is an employee who has at least 1 other employee reporting
-- to them.

-- ek ek krke col deko

SELECT E1.employee_id, E1.name, count(E2.employee_id) as reports_count, ROUND(AVG(E2.age)) as average_age
FROM Employees as E1 INNER JOIN Employees E2
on E1.employee_id = E2.reports_to 
GROUP BY E1.employee_id, E1.name
ORDER BY employee_id ASC ;   
