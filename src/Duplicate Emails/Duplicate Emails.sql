# Write your MySQL query statement below
select distinct P.Email
from Person as P, Person as Q
where P.id != Q.id and P.Email = Q.Email