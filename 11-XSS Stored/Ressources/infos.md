## How did we found it
Tried to inject xss in name of feedback page (`url/index.php?page=feedback`) like this `<script>alert('hey')</script>` (delete max length in front) but the tag is escaped. tried to bypass the tag verification like this : `<script >alert('hey')</script >`.
And it works, the script tag is interpreted and `hey` is printed.
The verification for this breach seems to be broken, to get the flag you just need to input a character from the tag `<script>` in the name form and leave the comment form empty

## How to fix it
- To fix this xss injection (stored), we must escape tags.