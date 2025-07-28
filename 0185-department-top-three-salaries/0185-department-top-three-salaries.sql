# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary from employee e
LEFT JOIN Department d
on e.departmentId = d.id
where (select count(DISTINCT salary) from employee e2 where e2.departmentId = e.departmentId AND e2.salary >= e.salary) <= 3