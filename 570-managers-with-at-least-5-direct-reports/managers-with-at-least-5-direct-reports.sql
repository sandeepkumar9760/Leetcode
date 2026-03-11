# Write your MySQL query statement below
SELECT e.name
FROM Employee AS e
JOIN Employee AS p
ON e.id=p.managerId
GROUP BY e.id,e.name
HAVING COUNT(p.managerId)>=5;