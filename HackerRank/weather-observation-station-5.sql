(select CITY, length(CITY) as city_len from STATION order by city_len asc, CITY asc limit 1) 
UNION
(select CITY, length(city) as city_len from STATION order by city_len desc, CITY asc limit 1);
