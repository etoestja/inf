use theater;

/*
режиссеры по количеству пьес
*/

select director, count(*) from view1
group by director
order by count(*) desc