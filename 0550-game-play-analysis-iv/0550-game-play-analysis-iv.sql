WITH cte AS (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity 
    GROUP BY player_id
),
cte2 AS (
    SELECT player_id, DATE_ADD(first_login, INTERVAL 1 DAY) AS next_logging_day
    FROM cte
)
SELECT 
    ROUND(COUNT(DISTINCT a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM 
    Activity a
JOIN 
    cte2 c ON a.player_id = c.player_id AND a.event_date = c.next_logging_day;
