# Write your MySQL query statement below

#avg selling price of each product = sare product ka  = groupby product
#and left join kro

SELECT P.product_id, IFNULL(ROUND(SUM(P.price * US.units ) / SUM(US.units),2),0) as average_price from Prices as P
LEFT JOIN UnitsSold as US
ON P.product_id = US.product_id AND
US.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY P.product_id;

