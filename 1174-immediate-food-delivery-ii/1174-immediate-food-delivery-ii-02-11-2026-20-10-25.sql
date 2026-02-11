# Write your MySQL query statement below

# sare customer_id ka 1st order me percentage of immediate orders

SELECT ROUND(SUM(IF(order_date = customer_pref_delivery_date, 1, 0 ))
*100 / (COUNT(DISTINCT customer_id)), 2) as immediate_percentage from Delivery where (customer_id, order_date) in
(SELECT customer_id, MIN(order_date) from Delivery GROUP BY customer_id);