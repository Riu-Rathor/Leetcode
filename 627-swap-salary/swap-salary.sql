# Write your MySQL query statement belo
UPDATE Salary set sex=
CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;