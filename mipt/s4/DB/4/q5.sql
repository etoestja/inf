use theater;

/*
самое часто используемое место в театре
*/

select top 1 room.[name] as room, seat.seat, seat.row from seat, performance, seat_performance, room
where seat.id = seat_performance.seat and
seat_performance.performance = performance.id and
room.id = seat.room
group by seat.seat, seat.row, room.[name]
order by count(performance.id) desc