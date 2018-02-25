# Write your MySQL query statement below
# The idea is to get the highest salary for each department. This needs a GROUP BY to achieve. So we end up with something like this
# {(1200,1#), (3000,2)} which means for Department 1, highest Salary is 1200, for Department 2, highest Salary is 3000. We can only get so   # little information is because the limit of use of GROUP BY. You can only select Aggregate value or the column in the Group By.

# Then we need to join Employee, Department and the result we got in the previous step so that we can select all employee that has the       # highest Salary in each department.

select Department.Name as Department, Employee.Name as Employee, Employee.Salary as Salary
from Employee,Department,(select max(salary) as maxs, DepartmentId as did
                          from Employee, Department
                          where Employee.DepartmentId = Department.id
                          group by Employee.DepartmentId) as cand
where Employee.DepartmentId = cand.did and Employee.Salary = cand.maxs and Employee.DepartmentId = Department.id