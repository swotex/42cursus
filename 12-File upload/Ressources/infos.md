## How did we found it
This one can be found on the add image page (`url/?page=upload`), you have to upload a file that's not an image file.
To pass an unauthorized file as image, we modified the `Content-Type` of the file to `image/jpeg` with python script (see `add_image.py`) or burpsuite proxy.

## How to fix it
- Never trust information that come from users
- Check extentions (beware of double and fake extensions)
- Check if extension and file type match
- Check image signature (beware of Magic bytes)
- Check MIME type (Can be usurped)