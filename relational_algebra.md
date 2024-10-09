### 1. **Relational Query Language**
- **SQL**: Structured Query Language (SQL) is a **declarative** language used at the application level to describe queries on a relational database.
- **Relational Algebra**: It is a **procedural** query language, used as an intermediate language inside a Database Management System (DBMS) to perform queries. SQL operates declaratively, while relational algebra describes **how** to retrieve the data.

### 2. **What is an Algebra?**
- **Algebra** is a mathematical system that consists of:
  - **Operands**: These are variables or values that can be combined to form new values.
  - **Operators**: Symbols that denote operations, allowing us to combine values (e.g., `+` for addition).

### 3. **Relational Algebra**
- **Relational Algebra** is an algebra whose **operands** are relations (or tables), and it operates on these relations using **operators** to retrieve or manipulate the data.
- **Operators** in relational algebra include:
  - **Union (∪)**
  - **Difference (−)**
  - **Product (×)**
  - **Projection (π)**
  - **Selection (σ)**
  - **Renaming (ρ)**

These operators perform the most common actions needed for querying a database.

### 4. **Relational Algebra Operators**
Relational Algebra consists of several operators that perform actions on relations. Here's a breakdown of the core operators:

#### a. **Selection (σ)**:
- **Definition**: Selects rows that satisfy a particular condition.
- **Example**: To retrieve all rows from the `Person` table where the `Hobby` is 'stamps':

  ```sql
  σ Hobby = 'stamps' (Person)
  ```

  This will return all rows in the `Person` table where the hobby is 'stamps'.

#### b. **Projection (π)**:
- **Definition**: Selects a subset of columns from the relation.
- **Example**: To retrieve only the `Name` and `Hobby` columns from the `Person` table:

  ```sql
  π Name, Hobby (Person)
  ```

  This will produce a table containing only the `Name` and `Hobby` columns, excluding any duplicates.

#### c. **Union (∪)**:
- **Definition**: Combines two relations by returning all tuples that appear in either relation.
- **Example**:

  ```sql
  (SELECT artist FROM Pop_albums)
  UNION
  (SELECT artist FROM Band_members)
  ```

  This query will return all unique artists from both the `Pop_albums` and `Band_members` tables.

#### d. **Set Difference (−)**:
- **Definition**: Returns tuples in one relation but not in another.
- **Example**:

  ```sql
  π Name (Person) − π Name (Professor)
  ```

  This returns the names of people in the `Person` table but not in the `Professor` table.

#### e. **Cross Product (×)**:
- **Definition**: Combines two relations by pairing each row from the first relation with every row from the second relation.
- **Example**:

  If `Person` has 3 rows and `Professor` has 2 rows, the cross-product `Person × Professor` will result in 6 rows, combining every possible pair.

#### f. **Rename (ρ)**:
- **Definition**: Renames the attributes of a relation to new names.
- **Example**:

  ```sql
  ρ (NewName, NewAddr)(Person)
  ```

  This renames the columns `Name` and `Address` in the `Person` table to `NewName` and `NewAddr`.

### 5. **Set Operators in Relational Algebra**
Set operators like **Union (∪)**, **Intersection (∩)**, and **Set Difference (−)** work on relations, just as they do in set theory, but only on **union-compatible** relations.

#### Union-Compatible Relations:
- Two relations are union-compatible if:
  - They have the same number of attributes (columns).
  - Corresponding attributes have the same domain (data type).

  Example:
  - `Person (SSN, Name, Address)`
  - `Professor (Id, Name, Office)`

  These relations are **not** union-compatible because the attribute names and numbers differ.

### 6. **Joins in Relational Algebra**
Joins are a way to combine two relations based on matching attribute values.

#### a. **Natural Join (⨝)**:
- Combines two relations by matching rows where attributes that exist in both relations have equal values.
- Example:

  ```sql
  Person ⨝ Professor
  ```

  Combines `Person` and `Professor` where matching values exist in both relations.

#### b. **Theta Join (θ-join)**:
- Combines two relations where the join condition (θ) is based on any arbitrary comparison (`<`, `>`, `=`, etc.).
- Example:

  ```sql
  R1 ⨝ S1 ON R1.age = S1.age
  ```

  Joins `R1` and `S1` where the `age` values match.

#### c. **Outer Joins (Left, Right, Full)**:
- **Left Outer Join**: Includes all rows from the left relation and matching rows from the right relation. If there’s no match, it fills in with `NULL`.
- **Right Outer Join**: Includes all rows from the right relation and matching rows from the left relation.
- **Full Outer Join**: Includes all rows from both relations, filling `NULL` where necessary.

### 7. **Division (÷)**
- **Definition**: Returns rows from one relation where tuples in that relation match every tuple in another relation.
- **Example**: Find the sailors who have reserved all boats.

  ```sql
  Sailor ÷ Boats
  ```

  This will return all sailors who have reserved every boat listed in the `Boats` table.
