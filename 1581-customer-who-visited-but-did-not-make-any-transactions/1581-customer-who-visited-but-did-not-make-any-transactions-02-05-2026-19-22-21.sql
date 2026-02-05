# Write your MySQL query statement below
#Visits -> visit_id is primary key and forign key for Transactions
#Transaction ->transaction_id is the primary key

#Visits me hai customer_id but Transactions me ni hai

select V.customer_id, COUNT(V.visit_id) as count_no_trans from 
Visits as V LEFT JOIN transactions as T 
on V.visit_id = T.visit_id WHERE T.transaction_id is NULL
GROUP BY V.customer_id; 

#m-2:
-- SELECT customer_id, COUNT(visit_id) as count_no_trans 
-- FROM Visits
-- WHERE visit_id NOT IN (
-- 	SELECT visit_id FROM Transactions
-- 	)
-- GROUP BY customer_id