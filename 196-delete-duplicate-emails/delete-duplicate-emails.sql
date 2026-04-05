DELETE FROM Person p
USING Person d
WHERE p.email = d.email
AND p.id > d.id;