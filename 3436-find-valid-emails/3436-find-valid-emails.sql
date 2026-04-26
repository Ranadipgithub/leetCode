# Write your MySQL query statement below
select * from Users 
where email regexp '^[a-z0-9_]+@[a-z]+\\.com$' order by user_id asc;