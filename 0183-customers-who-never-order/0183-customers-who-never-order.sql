# Write your MySQL query statement below
Select Customers.name AS Customers
FROM Customers
LEFT JOIN Orders
ON Customers.id = Orders.CustomerId
WHERE Orders.CustomerId is NULL;