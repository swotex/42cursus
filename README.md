# ft_printf

### 🎯 Objective

Reimplement a simplified version of `printf` with support for several format specifiers and handle output to the standard output.

### 📁 Supported Format Specifiers


| Specifier | Description              |
| :---------: | -------------------------- |
|   `%c`   | Character                |
|   `%s`   | String                   |
|   `%p`   | Pointer (memory address) |
|   `%d`   | Signed decimal integer   |
|   `%i`   | Signed decimal integer   |
|   `%u`   | Unsigned decimal integer |
|   `%x`   | Lowercase hexadecimal    |
|   `%X`   | Uppercase hexadecimal    |
|   `%%`   | Literal percent sign     |

### 📌 Constraints

- no use of standard `printf`, `sprintf`, or `asprintf`
- only `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy` and `va_end` are allowed
- must follow 42 coding standards

### ⚙️ Install

```bash
make
```

### 🧪 Usage

Include in your project

```c
#include "ft_printf.h"
```

And compile with the created archive

```bash
gcc main.c libftprintf.a
```

### ✅ Pedagogical objectives

- Handling variadic functions (stdarg.h)
- Parsing and interpreting format strings
- Managing memory and edge cases

### 🧠 Autor

- Nicolas JEGAT - [@swotex](https://github.com/swotex)

### 🏁 Project Status

Finished.
Final score: **100%**
