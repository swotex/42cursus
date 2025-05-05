# get_next_line

### 🎯 Objective

Implement a function that returns a line read from a file descriptor, one call at a time, including the newline character (`\n`) if it exists.

### 📁 Project content

- Reads from a file descriptor until it finds a newline or reaches EOF.
- Returns the next line each time it's called.
- Handles multiple file descriptors simultaneously.

### 📌 Constraints

- Only use allowed functions: `read`, `write` and `free`.
- Must work with any file descriptor (e.g., files, stdin, pipes).
- Must be memory-safe and leak-free
- Function must handle **BUFFER_SIZE** defined at compile-time

### ⚙️ Install

```bash
make
```

### 🧪 Usage

Include in your project

```c
#include "get_next_line.h"
```

And compile with:

```bach
gcc main.c get_next_line.c get_next_line_utils.c BUFFER_SIZE=42
```

OR

```bach
gcc main.c get_next_line_bonus.c get_next_line_utils_bonus.c BUFFER_SIZE=42
```

### ✅ Pedagogical objectives

- Mastering reading from file descriptors
- Managing internal static buffers
- Understanding memory allocation and line splitting
- Handling edge cases like EOF and empty lines

### 🧠 Autor

- Nicolas JEGAT - [@swotex](https://github.com/swotex/)

### 🏁 Project Status

Finished.
Final score: **100%**
