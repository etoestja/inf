SELECT Employee.* from Employee, Job, Department, Location

where employee.job_id=job.job_id
and employee.department_id=department.department_id
and department.location_id=location.location_id
and location.regional_group='DALLAS'
and job.[function] = 'MANAGER'