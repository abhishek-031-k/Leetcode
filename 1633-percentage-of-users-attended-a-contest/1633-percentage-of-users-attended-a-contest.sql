select
R.contest_id,
round(count(R.user_id)*100 /
(select count(U.user_id)from Users as U)
,2) as percentage
from Register as R
group by R.contest_id
order by percentage desc, contest_id asc