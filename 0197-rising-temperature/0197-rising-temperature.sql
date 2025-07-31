# Write your MySQL query statement below
select today.id
from weather yesterday
cross join weather today
where datediff(today.recordDate, yesterday.recordDate) = 1 AND today.temperature > yesterday.temperature;