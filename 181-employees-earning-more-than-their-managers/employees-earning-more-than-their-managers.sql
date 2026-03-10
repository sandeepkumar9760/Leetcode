SELECT e.name AS Employee
FROM Employee as e
JOIN Employee as b
ON e.managerId=b.id
WHERE e.salary > b.salary;