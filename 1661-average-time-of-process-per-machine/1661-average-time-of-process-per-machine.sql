select
a1.machine_id,
round(avg(a2.timestamp - a1.timestamp), 3) as processing_time 
from Activity as a1
inner join Activity as a2
on a1.machine_id = a2.machine_id
where a1.activity_type = 'start' and  a2.activity_type = 'end'
    group by a1.machine_id