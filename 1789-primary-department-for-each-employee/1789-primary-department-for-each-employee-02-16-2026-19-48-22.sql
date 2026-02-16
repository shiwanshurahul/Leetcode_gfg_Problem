# Write your MySQL query statement below

-- 2 department_id hai for a employee_id toh y wala lo
-- 1 department_id for a emplpoyee_id toh wo hi primary hai

SELECT DISTINCT employee_id, department_id
FROM Employee where employee_id in
(SELECT employee_id from Employee
GROUP BY employee_id HAVING COUNT(*) = 1)
or primary_flag = 'Y'
order by employee_id;

