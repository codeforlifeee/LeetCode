SELECT vt.customer_id, COUNT(*) AS count_no_trans
FROM Visits vt
LEFT JOIN Transactions tn
ON vt.visit_id = tn.visit_id
WHERE tn.visit_id IS NULL
GROUP BY vt.customer_id;