SELECT Department, Employee, Salary
FROM (
    SELECT 
        d.name AS Department, 
        e.name AS Employee, 
        e.salary AS Salary,
        DENSE_RANK() OVER (PARTITION BY d.name ORDER BY e.salary DESC) AS emp_rank
    FROM 
        Employee e
    LEFT JOIN 
        Department d ON e.departmentId = d.id
) AS newData
WHERE emp_rank <= 3;