# Write your MySQL query statement below
-- with cte as (
-- select d.name as Department, e.Name as Employee, e.salary as Salary, MAX(e.salary) OVER(PARTITION BY e.departmentId) as max_salary from Employee e
-- LEFT JOIN Department d
-- on e.departmentId=d.id)

-- Select Department, Employee, Salary from cte
-- where Salary = max_salary

with cte as
(select d.name as Department, e.name as Employee, e.salary as salary, max(e.salary) over(partition by e.departmentId) as max_salary from Employee e
Left Join department d
on e.departmentId = d.id)

select Department, Employee, Salary from cte
where salary = max_salary;