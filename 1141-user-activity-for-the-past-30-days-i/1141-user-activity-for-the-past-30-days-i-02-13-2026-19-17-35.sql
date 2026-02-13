# Write your MySQL query statement below

-- 2019-07-27 -> end date
-- 2019-06-28 -> start date (30 days before)
-- ek ek krke col deko

-- We need to count how many unique users were active each day within a given date range = groupby date

-- So:
-- Filter rows between two dates.
-- For each day, count distinct user_id.
-- Group results by date.

SELECT activity_date as day, count(DISTINCT user_id) 
as active_users from Activity
where activity_date between "2019-06-28" and " 2019-07-27"
group by activity_date;
