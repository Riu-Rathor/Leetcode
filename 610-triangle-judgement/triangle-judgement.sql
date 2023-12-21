# Write your MySQL query statement below
select * ,
CASE 
    WHEN x+y>z AND x+z>y AND z+y>x 
    THEN 'Yes'
    ELSE 'No'
END As triangle from Triangle;