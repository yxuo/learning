-- quotes

-- msql     'abc'
-- oracle   `abc`

-- login mysql
mysql -u root -p 1234

-- database
SHOW DATABASES;
-- add
CREATE DATABASE database1;
-- enter
USE database1;
-- remove
DROP DATABASE database1;

-- table
SHOW TABLES;
-- new table
CREATE TABLE tab(
    id INT PRIMARY KEY AUTO_INCREMENT,
    txt VARCHAR(40)
);
-- add line


-- show databases
CREATE TABLE IF NOT EXISTS tab(
    id INT PRIMARY KEY AUTO_INCREMENT,
    data VARCHAR(40)
);

-- 

