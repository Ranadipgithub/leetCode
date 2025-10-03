# Write your MySQL query statement below
select t.id from Weather t, weather y
where datediff(t.recordDate, y.recordDate) = 1 and t.temperature > y.temperature;