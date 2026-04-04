-- Write your PostgreSQL query statement below
SELECT pt.product_name, sl.year, sl.price
FROM Product pt
JOIN Sales sl
ON pt.product_id = sl.product_id
