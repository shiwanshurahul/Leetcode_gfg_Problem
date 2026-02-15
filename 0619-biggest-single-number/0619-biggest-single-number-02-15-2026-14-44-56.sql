# Write your MySQL query statement below

-- A single number is a number that appeared only once in the MyNumbers table.
-- Find the largest single number. If there is no single number, report null

-- SELECT MAX(num) as num from MyNumbers where num in
-- (select num from MyNumbers group by num having count(num)=1);

#subsquery sare single no de rha, 
-- and upar ka cod is picking max of it

-- m2:  -> coalesce
-- evaluates a list of expressions from left to right and returns the first non-NULL value encountered. If all expressions in the list are NULL, the function returns NULL. 


SELECT COALESCE( (SELECT num from MyNumbers group by num 
having count(num) = 1 
order by num desc LIMIT 1), NULL) as num;

