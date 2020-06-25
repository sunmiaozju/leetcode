-- use first_database;

-- CREATE TABLE `student` (
--     `s_id` VARCHAR(20),
--     `s_name` VARCHAR(20) NOT NULL DEFAULT "",
--     `s_birth` VARCHAR(20) NOT NULL DEFAULT "",
--     `s_sex` VARCHAR(20) NOT NULL DEFAULT "",
--     PRIMARY KEY(`s_id`)
-- );

-- CREATE TABLE `course`(
--     `c_id` VARCHAR(20),
--     `c_name` VARCHAR(20) NOT NULL DEFAULT '',
--     `t_id` VARCHAR(20) NOT NULL DEFAULT '',
--     PRIMARY KEY(`c_id`)
-- );

-- CREATE TABLE `teacher`(
--     `t_id` VARCHAR(20),
--     `t_name` VARCHAR(20) NOT NULL DEFAULT '',
--     PRIMARY KEY(`t_id`)
-- );

-- CREATE TABLE `score`(
--     `s_id` VARCHAR(20),
--     `c_id` VARCHAR(20),
--     `s_score` INT(3),
--     PRIMARY KEY(`s_id`, `c_id`)
-- );


-- insert into student values('02' , 'qiandian' , '1990-12-21' , 'male');
-- insert into student values('03' , 'sunfeng' , '1990-05-20' , 'male');
-- insert into student values('04' , 'liyun' , '1990-08-06' , 'male');
-- insert into student values('05' , 'zhoumei' , '1991-12-01' , 'female');
-- insert into student values('06' , 'wulan' , '1992-03-01' , 'female');
-- insert into student values('07' , 'zhengzhu' , '1989-07-01' , 'female');
-- insert into student values('08' , 'wangju' , '1990-01-20' , 'female');

-- insert into course values('01' , 'yuwen' , '02');
-- insert into course values('02' , 'shuxue' , '01');
-- insert into course values('03' , 'yingyu' , '03');
 
-- insert into teacher values('01' , 'zahngsan');
-- insert into teacher values('02' , 'lisi');
-- insert into teacher values('03' , 'wangwu');
 
-- insert into score values('01' , '01' , 80);
-- insert into score values('01' , '02' , 90);
-- insert into score values('01' , '03' , 99);
-- insert into score values('02' , '01' , 70);
-- insert into score values('02' , '02' , 60);
-- insert into score values('02' , '03' , 80);
-- insert into score values('03' , '01' , 80);
-- insert into score values('03' , '02' , 80);
-- insert into score values('03' , '03' , 80);
-- insert into score values('04' , '01' , 50);
-- insert into score values('04' , '02' , 30);
-- insert into score values('04' , '03' , 20);
-- insert into score values('05' , '01' , 76);
-- insert into score values('05' , '02' , 87);
-- insert into score values('06' , '01' , 31);
-- insert into score values('06' , '03' , 34);
-- insert into score values('07' , '02' , 89);
-- insert into score values('07' , '03' , 98);

-- SELECT 
-- a.s_id, a.s_name, 
-- ROUND(AVG(b.s_score), 2) AS score
-- FROM student a 
-- JOIN score b
-- ON a.s_id = b.s_id
-- GROUP BY a.s_id
-- HAVING AVG(b.s_score) >= 60;

-- SELECT
-- b.c_name ,COUNT(*)
-- FROM score a
-- JOIN course b 
-- ON a.c_id = b.c_id
-- GROUP BY a.c_id;

-- SELECT 
-- a.c_id, b.c_name, MAX(a.s_score), MIN(a.s_score), AVG(a.s_score)    , 
-- ROUND(100*(SUM(case when a.s_score >=60 then 1 else 0 end)/SUM(case when a.s_score >= 0 then 1 else 0 end)),2)
-- FROM score a
-- LEFT JOIN course b
-- ON a.c_id = b.c_id
-- GROUP BY a.c_id;



SELECT a.*, 
b.s_score AS '01Score', 
c.s_score AS "02Score" 
FROM student a 
JOIN score b 
ON a.`s_id`=b.`s_id` AND b.`c_id`=01 
JOIN score c 
ON a.`s_id`=c.`s_id` AND c.`c_id`=02 
;
