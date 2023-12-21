# Write your MySQL query statement below
select e.name, b.bonus from Employee e LEFT JOIN Bonus b ON e.empid = b.empid where b.bonus < 1000 OR bonus IS NULL;