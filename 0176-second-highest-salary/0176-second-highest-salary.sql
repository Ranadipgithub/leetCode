# Write your MySQL query statement below
select Max(salary) AS SecondHighestSalary from Employee where salary < (select MAX(salary) from Employee);