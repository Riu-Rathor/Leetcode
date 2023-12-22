# Write your MySQL query statement below
select project_id, ROUND(AVG(experience_years), 2) as average_years from Project p JOIN Employee e ON p.employee_id = e.employee_id GROUP BY p.project_iD;