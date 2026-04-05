SELECT 
    ROUND(
        COUNT(DISTINCT a1.player_id) * 1.0 /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM Activity a1
JOIN (
    SELECT player_id, MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
) a2
ON a1.player_id = a2.player_id
WHERE a1.event_date = DATE_ADD(a2.first_date, INTERVAL 1 DAY);