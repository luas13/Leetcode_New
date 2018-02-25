# Write your MySQL query statement below
select Name
from Customers c
where not exists ( select CustomerId 
                   from Orders o 
                   where o.CustomerId = c.id )
                   
#select Name 
#from Customers c
#where c.id not in ( select Customerid
#                    from orders )