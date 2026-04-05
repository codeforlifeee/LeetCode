# Write your MySQL query statement below
SELECT ct.customer_id 
FROM Customer ct
JOIN Product pt
ON ct.product_key = pt.product_key
GROUP BY customer_id
HAVING  COUNT(DISTINCT ct.product_key) = (SELECT COUNT(*) FROM Product);