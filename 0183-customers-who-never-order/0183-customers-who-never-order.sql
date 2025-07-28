# Write your MySQL query statement below
select c.name as Customers from Customers c
left join Orders d
on c.id=d.customerId
where d.customerId is NULL