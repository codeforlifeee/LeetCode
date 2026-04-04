# Write your MySQL query statement below
SELECT pt.project_id,     ROUND(AVG(e.experience_years), 2) AS average_years
FROM Project pt
JOIN Employee e
ON pt.employee_id = e.employee_id
GROUP BY pt.project_id;