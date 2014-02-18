select location.regional_group as City, sum(case when job.[function] = 'MANAGER' then 1 else 0 end) as 'MANAGERs',
sum(case when job.[function] = 'SALESPERSON' then 1 else 0 end) as 'SALESPERSONs'
from location, employee, department, job
where
employee.department_id = department.department_id
and department.location_id = location.location_id
and employee.job_id = job.job_id
group by location.regional_group