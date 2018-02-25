# Write your MySQL query statement below
select P.Name 
from Employee as P, Employee as Q
where P.ManagerId = Q.id and P.Salary > Q.Salary