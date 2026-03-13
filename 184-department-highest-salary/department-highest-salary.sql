# Write your MySQL query statement below
SELECT d.name as Department , e.name as Employee , e.salary as Salary
FROM Employee AS e
JOIN Department AS d
ON e.departmentId = d.id
WHERE e.salary = (SELECT MAX(salary) FROM Employee WHERE departmentId=d.id);
