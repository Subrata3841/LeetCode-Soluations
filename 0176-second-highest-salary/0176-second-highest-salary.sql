# Write your MySQL query statement below
Select IFNULL((
    Select DISTINCT salary
    From Employee
    Order By salary DESC
    LIMIT 1 OFFSET 1
), NULL) AS  SecondHighestSalary