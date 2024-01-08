CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      Select salary from Employee e1 where N-1 = (Select count(Distinct salary) from Employee e2 where e2.salary > e1.salary) LIMIT 1
    #  SELECT DISTINCT(salary) from Employee order by salary DESC  LIMIT 1 OFFSET N

  );
END