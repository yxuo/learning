-- quotes

-- msql     'abc'
-- oracle   `abc`

-- login mysql
mysql -u root -p 1234

-- DATABASE --
SHOW DATABASES;
-- add
CREATE DATABASE database1;
-- enter
USE database1;
-- remove
DROP DATABASE database1;

-- TABLE --
SHOW TABLES;
-- new table
CREATE TABLE tab(
    id INT PRIMARY KEY AUTO_INCREMENT,
    txt VARCHAR(40)
);
-- add line
INSERT INTO tab(txt) VALUES('abcde');
-- add line if not duplicated
INSERT IGNORE INTO tab(txt) VALUES('abcde')
-- add line if in
INSERT INTO tab(txt) VALUES('abcde')
WHERE NOT IN (SELECT id FROM tab WHERE id = 1);
-- add multiple lines
INSERT ALL
INTO tab(txt) VALUES('line 1')
INTO tab(txt) VALUES('line 2')
-- SELECT at last line is mandatory, ignore it.
SELECT 1 FROM DUAL;

-- remove line
DELETE FROM tab WHERE id=1;
-- remove if match
DELETE FROM tab WHERE id in ('text content');

-- show databases
CREATE TABLE IF NOT EXISTS tab(
    id INT PRIMARY KEY AUTO_INCREMENT,
    data VARCHAR(40)
);

-- change values
UPDATE tab
SET col1 = val1, col2 = val2
WHERE id = 0

-- 

