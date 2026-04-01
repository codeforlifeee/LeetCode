CREATE OR REPLACE FUNCTION NthHighestSalary(N INT)
RETURNS TABLE (Salary INT) AS $$
BEGIN
    -- If N <= 0, return NULL immediately
    IF N <= 0 THEN
        RETURN QUERY SELECT NULL::INT;
        RETURN;
    END IF;

    RETURN QUERY
    SELECT t.salary
    FROM (
        SELECT DISTINCT e.salary
        FROM Employee e
        ORDER BY e.salary DESC
    ) AS t
    OFFSET N-1
    LIMIT 1;
END;
$$ LANGUAGE plpgsql;