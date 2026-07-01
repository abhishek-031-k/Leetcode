select 
P.product_name,
s.year,
s.price
from Sales as s
left join Product as P
on P.product_id = s.product_id