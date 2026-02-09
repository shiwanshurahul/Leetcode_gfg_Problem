# Write your MySQL query statement below

#avg selling price of each product = sare product ka  = groupby product
#and left join kro

-- Prices are valid only within a specific date range, so for each sale, we must pick the correct price based on the date.
-- so, US.purchase_date BETWEEN P.start_date AND P.end_date
-- If a product has no sales, its average price should be 0.

SELECT P.product_id, IFNULL(ROUND(SUM(P.price * US.units ) / SUM(US.units),2),0) as average_price from Prices as P
LEFT JOIN UnitsSold as US
ON P.product_id = US.product_id AND
US.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY P.product_id;

