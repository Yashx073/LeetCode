# Write your MySQL query statement below
SELECT e.name AS Employee
FROM Employee e
JOIN Employee s
    ON s.id = e.managerId
WHERE e.Salary > s.Salary;