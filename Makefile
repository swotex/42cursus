LIBNAME = libasm.a

NASM = nasm

ASMFLAGS = -f elf64

GCC = gcc

GCCFLAGS = -Werror -Wextra -Wall

TESTNAME = libasm_test

SRC = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

OBJ = $(SRC:%.s=%.o)

%.o: %.s
	@$(NASM) $(ASMFLAGS) $< -o $@

$(LIBNAME): $(OBJ)
	@ar rcs $(LIBNAME) $(OBJ)
	@echo "\033[4;32m--- Lib created ---\n\033[0m"

all: $(LIBNAME)

test: all
	@$(GCC) $(GCCFLAGS) test.c $(LIBNAME) -o $(TESTNAME)
	@echo "\033[4;32m--- Executable created ---\n\033[0m"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(BOBJ)

fclean: clean
	@rm -rf $(TESTNAME) $(LIBNAME)
	@echo "\033[4;35m--- all creations have been deleted ---\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus