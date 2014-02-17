/*
e1 < e2
*/
select distinct e2.first_name + ' ' + e2.middle_initial + ' ' + e2.last_name as name from employee e1, employee as e2
where e1.manager_id=e2.employee_id
and e1.job_id in (select job_id from job where [function]='ANALYST')
and e2.job_id in (select job_id from job where [function]='MANAGER')
and e1.hire_date <= dateadd(year, 5, e2.hire_date)
and e1.hire_date >= e2.hire_date