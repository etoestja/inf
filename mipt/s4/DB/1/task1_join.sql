SELECT Employee.* from Employee

JOIN Job ON  employee.job_id=job.job_id
JOIN Department ON employee.department_id=department.department_id
JOIN Location ON department.location_id=location.location_id

where location.regional_group='DALLAS' and job.[function] = 'MANAGER'