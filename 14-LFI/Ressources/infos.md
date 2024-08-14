## How did we found it
With the base url that loads all the page (`url/?page=.....`) we can do an LFI breach (local file inclusion).
To get the flag go at `url/?page=../../../../../../../etc/passwd`.

## How to fix it
- Forbid the presence of a slash `/` in the parameter
- Check parameter to verify if it's an authorized page