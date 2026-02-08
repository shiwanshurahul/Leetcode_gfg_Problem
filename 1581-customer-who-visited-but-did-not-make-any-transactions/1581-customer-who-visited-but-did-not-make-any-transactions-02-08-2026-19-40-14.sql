# Write your MySQL query statement below
#Visits -> visit_id is primary key and forign key for Transactions
#Transaction ->transaction_id is the primary key

#Visits me hai customer_id but Transactions me ni hai
# = sare customer_id chaiy from Visits = left join and
# groupby on it

-- A subquery in SQL is a query nested inside another SQL query. It allows complex filtering, aggregation and data manipulation by using the result of one query inside another. They can filter rows based on results from another query.
-- e.g. SELECT * FROM Students WHERE Score > ( SELECT AVG(Score) FROM Students );

-- The SQL GROUP BY clause is used to arrange identical data into groups based on one or more columns. It is commonly used with aggregate functions like COUNT(), SUM(), AVG(), MAX(), and MIN() to perform calculations on each group of data. -> same as pandas 
#groupby usiko kroge jisme multiple group ho primary key pe v kr skte  

-- If you use an aggregate function (like SUM) alongside a regular column (like mode), you must group by that regular column.
-- Without a GROUP BY clause here, the database doesn't know how to associate the single "Total Sum" with the multiple individual "Modes."

-- Key Differences: WHERE &. HAVING
-- Feature 	          WHERE Clause	        HAVING Clause
-- Operates On	      Individual rows.	   Aggregated data (groups).
-- Filtering Stage    Before GROUP BY      After GROUP BY and aggregatin
--                   and aggregation.

-- Aggregate Functions: Where Cannot be used with aggregate functions (e.g., COUNT(), SUM()).
# Having Can be used with aggregate functions.

select V.customer_id, COUNT(V.visit_id) as count_no_trans from 
Visits as V LEFT JOIN transactions as T 
on V.visit_id = T.visit_id where T.transaction_id is NULL
GROUP BY V.customer_id; 

#m-2:
-- SELECT customer_id, COUNT(visit_id) as count_no_trans 
-- FROM Visits
-- WHERE visit_id NOT IN ( SELECT visit_id FROM Transactions )
-- GROUP BY customer_id;