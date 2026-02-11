# Write your MySQL query statement below
-- each month and country : groupby kro dono pe
-- ek ek col krke chalo
-- approved_total_amount is jb approved ho only tb ka cnt

SELECT DATE_FORMAT(trans_date, '%Y-%m') AS month, country, COUNT(*) as trans_count, SUM(IF(state='approved', 1, 0)) as approved_count, SUM(amount) as trans_total_amount, SUM(IF(state='approved', amount, 0)) as approved_total_amount
from Transactions
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country;
