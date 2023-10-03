# SQL Problem

## Salesperson Table

### Structure:

| Field          | Type        | Null | Key | Default | Extra |
|----------------|-------------|------|-----|---------|-------|
| salesperson_id | int(11)     | YES  |     |         |       |
| first_name     | varchar(255)| YES  |     |         |       |
| last_name      | varchar(255)| YES  |     |         |       |

### Data:

| salesperson_id | first_name | last_name |
|----------------|------------|-----------|
| 1              | Green      | Wright    |
| 2              | Jones      | Collins   |
| 3              | Bryant     | Davis     |

## Address Table

### Structure:

| Field          | Type        | Null | Key | Default | Extra |
|----------------|-------------|------|-----|---------|-------|
| address_id     | int(11)     | YES  |     |         |       |
| salesperson_id | int(11)     | YES  |     |         |       |
| city           | varchar(255)| YES  |     |         |       |
| state          | varchar(255)| YES  |     |         |       |
| country        | varchar(255)| YES  |     |         |       |

### Data:

| address_id | salesperson_id | city         | state       | country |
|------------|----------------|--------------|-------------|---------|
| 1          | 2              | Los Angeles  | California  | USA     |
| 2          | 3              | Denver       | Colorado    | USA     |
| 3          | 4              | Atlanta      | Georgia     | USA     |
