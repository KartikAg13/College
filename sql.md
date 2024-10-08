### 1. **CREATE TABLE**
Used to create a new table:
```sql
CREATE TABLE Employee (
	Employee_id INTEGER,
	Employee_name VARCHAR(20),
	Employee_city VARCHAR(20)
);
```

### 2. **INSERT INTO**
To insert data into the table:
```sql
INSERT INTO Employee VALUES (111, 'David', 'Delhi');
INSERT INTO Employee VALUES (222, 'Peter', 'Delhi');
INSERT INTO Employee VALUES (333, 'Jane', 'Mumbai');
```

### 3. **SELECT**
To retrieve data:
```sql
-- Select all records
SELECT * FROM Employee;

-- Select employees from Delhi
SELECT * FROM Employee WHERE Employee_city = 'Delhi';

-- Select specific attribute (city) of employees
SELECT Employee_city FROM Employee;

-- Select distinct cities without duplicates
SELECT DISTINCT Employee_city FROM Employee;

-- Select with arithmetic expressions
SELECT Emp_name, Emp_Sal, Emp_Sal + 500 FROM Employee;
```

### 4. **UPDATE**
To update records in a table:
```sql
UPDATE Employee
SET Employee_city = 'Kolkata'
WHERE Employee_id = 111;
```

### 5. **DELETE**
To delete records from the table:
```sql
-- Delete all records from the Employee table where city is Delhi
DELETE FROM Employee WHERE Employee_city = 'Delhi';

-- Delete all records from Employee table
DELETE FROM Employee;
```

### 6. **AGGREGATE FUNCTIONS**
- **COUNT**: To count rows:
  ```sql
  SELECT COUNT(Employee_id) FROM Employee;
  ```

- **AVG**: To calculate the average salary:
  ```sql
  SELECT AVG(Employee_salary) FROM Employee;
  ```

- **SUM**: To calculate the total salary:
  ```sql
  SELECT SUM(Employee_salary) FROM Employee;
  ```

- **MAX and MIN**: To find the maximum and minimum values:
  ```sql
  SELECT MAX(Employee_salary) FROM Employee;
  SELECT MIN(Employee_salary) FROM Employee;
  ```

- **GROUP BY**: Group data and count employees in each department:
  ```sql
  SELECT Emp_dept, COUNT(*) AS Emp_count FROM Employee GROUP BY Emp_dept;
  ```

- **HAVING**: Filter groups with a condition:
  ```sql
  SELECT Emp_name FROM Employee GROUP BY Emp_name HAVING AVG(Emp_Sal) > 15000;
  ```

### 7. **JOINS**
- **INNER JOIN**: Fetch records matching between two tables.
  ```sql
  SELECT e.Employee_name, d.Department_name
  FROM Employee e
  INNER JOIN Department d ON e.Department_id = d.Department_id;
  ```

- **LEFT OUTER JOIN**: Fetch all records from the left table and matching ones from the right.
  ```sql
  SELECT e.Employee_name, d.Department_name
  FROM Employee e
  LEFT OUTER JOIN Department d ON e.Department_id = d.Department_id;
  ```

- **RIGHT OUTER JOIN**: Fetch all records from the right table and matching ones from the left.
  ```sql
  SELECT e.Employee_name, d.Department_name
  FROM Employee e
  RIGHT OUTER JOIN Department d ON e.Department_id = d.Department_id;
  ```

- **FULL OUTER JOIN**: Fetch all records from both tables:
  ```sql
  SELECT e.Employee_name, d.Department_name
  FROM Employee e
  FULL OUTER JOIN Department d ON e.Department_id = d.Department_id;
  ```

### 8. **BETWEEN and LIKE**
- **BETWEEN**: Select records within a range:
  ```sql
  SELECT * FROM Employee WHERE Emp_Sal BETWEEN 20000 AND 50000;
  ```

- **LIKE**: Pattern matching:
  ```sql
  -- Find employees with 'an' in their name
  SELECT * FROM Employee WHERE Employee_name LIKE '%an%';

  -- Find employees whose name ends with 'ane'
  SELECT * FROM Employee WHERE Employee_name LIKE '_ane';
  ```

### 9. **ORDER BY**
To order the result set:
```sql
-- Order employees by salary in descending order
SELECT Emp_name, Emp_Sal FROM Employee WHERE Emp_Sal > 25000 ORDER BY Emp_Sal DESC;

-- Order employees by name alphabetically
SELECT Emp_name FROM Employee WHERE Emp_Sal > 30000 ORDER BY Emp_name;
```

### 10. **SUBQUERIES**
- Subqueries nested within `SELECT`:
  ```sql
  SELECT Employee_name FROM Employee WHERE Department_id IN (
  	SELECT Department_id FROM Department WHERE Department_name = 'HR'
  );
  ```

- Using `EXISTS` to check if a subquery returns any records:
  ```sql
  SELECT Employee_name FROM Employee e WHERE EXISTS (
  	SELECT * FROM Department d WHERE d.Department_id = e.Department_id
  );
  ```

### 11. **CONSTRAINTS**
- **CHECK**: Ensures data integrity.
  ```sql
  CREATE TABLE Employee (
  	Employee_id INTEGER NOT NULL CHECK(Employee_id > 0),
  	Employee_Age INTEGER CHECK(Employee_Age > 20 AND Employee_city = 'Mumbai')
  );
  ```

### 12. **DEFAULT**
Sets default values for columns:
```sql
CREATE TABLE Employee (
	Employee_city VARCHAR(20) DEFAULT 'Mumbai'
);
```
