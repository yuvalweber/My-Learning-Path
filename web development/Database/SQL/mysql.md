# Commands
1) create database
```
CREATE DATABASE <name>;
```
2) move to a database
```
use <db_name>;
```
3) create table
```
CREATE TABLE <table_name> (
id INT NOT NULL,
name VARCHAR(30),
price VARCHAR(30),
PRIMARY KEY (id)
);
```

4) create table with foreign keys
```
CREATE TABLE <table_name> (
id INT NOT NULL,
name VARCHAR(30) ,
mail VARCHAR(30),
nickname VARCHAR(30),
PRIMARY KEY (id),
FOREIGN KEY (<column_from_our_table>) REFERENCES <other_table_name>(<primary_key_name>)
```
5) delete table
```
DROP TABLE <table_name>
```
6) check which key is primary in sql
```
SHOW KEYS FROM <table_name> WHERE Key_name = 'PRIMARY';
```
7) insert info into table
```
INSERT INTO <table_name>
VALUES ("","","");
```
8) insert info into table (not all columns)
```
INSERT INTO <table_name> (id,name)
VALUES (2,"danon");
```
9) change value in the database
```
UPDATE <table_name>
SET <column> = <value>
WHERE <statement>;
```
10) add columns to table
```
ALTER TABLE <table_name>
ADD <column_name> <data_type>;
```
11) delete record from table
```
DELETE FROM <table_name>
WHERE <statement>;
```
12) show columns of table
```
DESCRIBE <table_name>;
```
13) select from multiple tables
```
SELECT <something> FROM <table_name>
INNER JOIN <another_table_name>
ON <db_name>.<column_name> = <another_db_name>.<column_name>;
```
<b>exmple:</b>
```
SELECT * FROM CUSTOMERS
INNER JOIN users
ON CUSTOMERS.id = users.id;
```