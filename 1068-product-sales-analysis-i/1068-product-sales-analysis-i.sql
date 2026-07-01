select 
P.product_name,
s.year,
s.price
from Sales as s
inner join Product as P
on P.product_id = s.product_id