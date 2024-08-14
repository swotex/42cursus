## How did we found it
We found it on page `url/?page=b7e44c7a40c5f80139f0a50f3650fb2bd8d00b0d24667c4c2ca32c88e13b758f` by inspecting this page code we can find 2 interesting comments :
- `You must come from : "https://www.nsa.gov/"`
- `Let's use this browser : "ft_bornToSec". It will help you a lot.`

For the first one we have to use the keyword `Referer` in the request header to tell the site that we come from `https://www.nsa.gov/`.

For the second one we have to add `User-Agent` to the same header to tell the site that we use `ft_bornToSec` as a browser.

The final header looks like this: (used in the script `albatroz.py`)
```py
{'User-Agent': "ft_bornToSec", 'Referer': "https://www.nsa.gov/"}
```

## How to fix it
- Do not rely on `User-Agent` and `Referer` infos because they can be modified easily