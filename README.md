# Libtf

### 🎯 Objective

Libft is a project to recreate certain functions of the standard C library, while respecting strict coding standards. The project aims to reinforce C basics and understanding of memory management, pointers and strings.

### 📁 Project content

The libft consists of three main parts :

#### 1. First part: libc functions

- `memset`, `memcpy`, `memmove`, `memcmp`, `memchr`
- `strlen`, `strchr`, `strrchr`, `strncmp`, `strdup`, `strnstr`, `strlcpy`, `strlcat`
- `isalum`, `isalpha`, `isascii`, `isdigit`, `isprint`
- `atoi`, `calloc`, `bzero`
- `toupper`, `tolower`

#### 2. Second part: utilities functions

- `substr`, `strjoin`, `strtrim`, `split`
- `itoa`, `strmapi`, `striteri`
- `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`

#### 3. Bonus part: liked list functions

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`
- `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### ⚙️ Install

```bash
make
```

Or compile with bonus

```bash
make bonus
```

### 🧪 Usage

Include the library in your project

```c
#include "libft.h"
```

And compile with the created archive

```bash
gcc main.c libft.a
```

### ✅ Pedagogical objectives

- Solid understanding of pointers and memory allocation
- In-depth knowledge of how common C functions work under the hood
- Introduction to data structures (bonus)

### 🧠 Autor

- Nicolas JEGAT - [@swotex](https://github.com/swotex)

### 🏁 Project Status

Finished with bonus.
Final score: **104%**
