# Write your MySQL query statement below

-- For each product_id, identify the earliest year it appears in the Sales table = groupby on product_id

SELECT product_id, year as first_year, quantity, 
price from Sales
where (product_id, year) in
(SELECT product_id, min(year) from Sales
group by product_id);

