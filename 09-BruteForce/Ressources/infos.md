## How did we found it
### Sql way :
Got the name of database of table db_user (found previously) with sql (on member page) ```42 UNION SELECT table_schema AS database_name, table_name FROM information_schema.tables WHERE table_name=CHAR(100, 98, 95, 100, 101, 102, 97, 117, 108, 116)```
We found `Member_Brute_Force` as database after we get all ids in db_default with ```42 UNION SELECT id, NULL FROM Member_Brute_Force.db_default```
we found 2 users, we printed it width ```42 UNION SELECT username, password FROM Member_Brute_Force.db_default WHERE id=1```.
We tried with id 1 and 2, both have the same password and the usernames are `admin` and `root` (they both lead to the same flag).
### Brute force way:
The username and password used for connection are directly in the link (get method).
To brute force the signin (`url/?page=signin`) we made a script (`BrutPassword.py`) that does requests with a username (input by user) and a list of most commons passwords we found online

## How to fix it
- In the backend, the sql request need to be prepared, in this case sql can't be injected
- Password is too weak (`shadow`) (easy bruteforce)
- The get method is not the most appropriate for a connection
- The password can be salted when is hashed
- Limit max tries for connection