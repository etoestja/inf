use theater;

/*
пьесы по общему количеству зрителей
*/

select play.[name], count(distinct seat.id) as seats from play, play_staging, staging, performance, seat_performance, seat
where play.id = play_staging.play and
play_staging.staging = staging.id and
performance.staging = staging.id and
performance.id = seat_performance.performance and
seat.id = seat_performance.seat
group by play.[name]
order by count(distinct seat.id) desc