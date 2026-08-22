select
R.contest_id,
round(count(R.user_id)*100 /
(select count(U.user_id)from Users as U)
,2) as percentage
from Users as U
left join Register as R
on R.user_id = U.user_id
group by R.contest_id
order by percentage desc, contest_id asc