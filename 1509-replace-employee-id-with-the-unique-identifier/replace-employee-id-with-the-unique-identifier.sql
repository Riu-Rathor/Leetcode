# Write your MySQL query statement below
select unique_id, name from Employees e LEFT JOIN EmployeeUNI u ON e.id = u.id;