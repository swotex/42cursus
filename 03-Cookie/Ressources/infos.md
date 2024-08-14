## How did we found it
obtained by looking at cookies on page, there is a cookie `I_am_admin=68934a3e9455fa72420237eb05902327` this is an MD5 encrypted `false` so we replace it by `I_am_admin=b326b5062b2f0e69046810717534cb09` which is `true` in MD5

## How to fix it
- Don't store this variable in front, store it in DB