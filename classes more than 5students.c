# Write your MySQL query statement below

SELECT class 
FROM (
       SELECT COUNT(student), class
       FROM Courses
       GROUP BY class
       HAVING COUNT(student) >=5
    ) sq; 
