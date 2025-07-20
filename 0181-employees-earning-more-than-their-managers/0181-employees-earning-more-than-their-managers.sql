# Write your MySQL query statement belo
SELECT e2.name as Employee
FROM Employee e1
JOIN Employee e2 ON e2.managerId = e1.id
WHERE e2.salary > e1.salary;