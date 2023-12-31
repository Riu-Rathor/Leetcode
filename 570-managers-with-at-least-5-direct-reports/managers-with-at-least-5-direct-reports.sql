# Write your MySQL query statement below
select e.name from Employee e INNER JOIN Employee b ON e.id = b.managerId GROUP BY b.managerId Having Count(b.managerId) >= 5;