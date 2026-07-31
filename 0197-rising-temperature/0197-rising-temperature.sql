select W1.id
from Weather as W1
cross join Weather as W2
where datediff(day, W2.recordDate, W1.recordDate) = 1 and
      W1.temperature > W2.temperature