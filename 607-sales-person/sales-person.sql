# Write your MySQL query statement below
select s.name
 from SalesPerson s
 WHERE s.name not in 
 (select s.name from SalesPerson s
  LEFT JOIN Orders o ON s.sales_id = o.sales_id
  LEFT JOIN Company c ON o.com_id = c.com_id
  where c.name = 'RED');