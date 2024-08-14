## How did we found it
On the home page there is an nsa image that lead to a link (`url/?page=media&src=nsa`).
We can inject a script encoded in Base64 after the `src=` to get the flag (see `Base64script.py`).
Base64 permit us to bypass protections against scripts.

## How to fix it
- Don't trust user input
- Don't use get request to access your backend files
- Protect against direct data inputs with backend verification