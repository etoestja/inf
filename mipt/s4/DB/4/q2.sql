use theater;

select director.name_first + ' ' + director.surname as name, count(distinct play.id) as Plays from director, staging, play_staging, play
where
director.id = staging.director and
staging.id = play_staging.staging and
play_staging.play = play.id
group by director.id, director.name_first, director.name_middle, director.surname
order by count(distinct play.id) desc