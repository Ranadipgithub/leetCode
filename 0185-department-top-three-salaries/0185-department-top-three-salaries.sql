select Department, Employee, Salary from (SELECT 
    d.name AS Department, 
    e.name AS Employee, 
    e.salary AS Salary,
    DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS SalaryRank
FROM Employee e
LEFT JOIN Department d 
    ON e.departmentId = d.id) as ranks
where SalaryRank <= 3;