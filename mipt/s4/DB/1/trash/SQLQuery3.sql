select count(*) from employee
where employee.job_id in (select job_id from job where [function]='ANALYST')