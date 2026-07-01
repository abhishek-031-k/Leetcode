select o.unique_id,
e.name from Employees as e
left join EmployeeUNI as o
on e.id = o.id