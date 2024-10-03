LIBNAME = libasm.a

LIBNAMEB = libasm_bonus.a

NASM = nasm

ASMFLAGS = -f elf64 -g

GCC = gcc

GCCFLAGS = -Werror -Wextra -Wall -g

TESTNAME = libasm_test

SRC = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

BSRC = ft_atoi_base_bonus.s \
		ft_list_push_front_bonus.s

OBJ = $(SRC:%.s=%.o)
BOBJ = $(BSRC:%.s=%.o)

%.o: %.s
	@$(NASM) $(ASMFLAGS) $< -o $@

$(LIBNAME): $(OBJ)
	@ar rcs $(LIBNAME) $(OBJ)
	@echo -e "\033[4;32m--- Lib created ---\n\033[0m"

$(LIBNAMEB): $(OBJ) $(BOBJ)
	@ar rcs $(LIBNAMEB) $(OBJ) $(BOBJ)
	@echo -e "\033[4;32m--- Lib bonus created ---\n\033[0m"

all: $(LIBNAME)

bonus: $(LIBNAMEB)

test: all
	@$(GCC) $(GCCFLAGS) test.c $(LIBNAME) -o $(TESTNAME)
	@echo -e "\033[4;32m--- Executable created ---\n\033[0m"

test_bonus: bonus
	@$(GCC) $(GCCFLAGS) main_bonus.c $(LIBNAMEB) -o $(TESTNAME)
	@echo -e "\033[4;32m--- Executable bonus created ---\n\033[0m"

clean:
	@rm -rf $(OBJ) $(BOBJ)

fclean: clean
	@rm -rf $(TESTNAME) $(LIBNAME) $(LIBNAMEB)
	@echo -e "\033[4;35m--- all creations have been deleted ---\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus