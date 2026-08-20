select
p.product_id,
round(coalesce(((sum(p.price* u.units))/sum(u.units)),0), 2) as average_price
from Prices as p
left join UnitsSold as u
on p.product_id = u.product_id
and u.purchase_date between start_date and end_date
group by product_id