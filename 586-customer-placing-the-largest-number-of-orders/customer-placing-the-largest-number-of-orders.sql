# Write your MySQL query statement below
select customer_number from Orders group by customer_number ORDER BY Count(*) DESC LIMIT 1;