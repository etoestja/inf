select regional_group,
count(case when job.[function] = 'SALESPERSON' then 1 else 0 end) as 'SALESPERSONs',
count(case when job.[function] = 'MANAGER' then 1 else 0 end) as 'MANAGERs'
from location, employee, department, job
where
employee.department_id = department.department_id
and department.location_id = location.location_id
and employee.job_id = job.job_id
group by location.regional_group