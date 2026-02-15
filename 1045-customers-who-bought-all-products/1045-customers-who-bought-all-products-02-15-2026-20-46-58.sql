# Write your MySQL query statement below

-- customer ids from the Customer table that bought all the products in the Product table.

-- Find customers where customer_unique_products = total_store_products

-- Use COUNT(DISTINCT product_key) to count unique products per customer


SELECT customer_id from Customer GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = 
(SELECT COUNT(*) FROM Product);
