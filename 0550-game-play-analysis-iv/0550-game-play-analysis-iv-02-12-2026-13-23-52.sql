# Write your MySQL query statement below

#sare player_id me check krna hai = groupby lagao

-- fraction of players that logged in again on the day after the day they first logged in

-- = each player_id ka check kro ki event_date is consecutive?


SELECT player_id, (COUNT(DISTINCT player_id))
(SELECT player_id, from Activity
GROUP BY player_id);


-- _percentage 
-- from Delivery where (customer_id, order_date) in
-- (SELECT customer_id, MIN(order_date) from Delivery 
-- GROUP BY customer_id);   #for all customer_id






