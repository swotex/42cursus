## How did we found it

obtained by connexion as root on the website `/admin`.
The user and password are obtained by the htpasswd file (at `/whatever` given in `/robots.txt`).
The htpasswd password is generally encrypted in MD5 or SHA1, we use a famous hash list to find the password (https://crackstation.net).

## How to fix it
- Get a better password
- Delete the htpasswd from the server
- Blacklist `/whatever` url