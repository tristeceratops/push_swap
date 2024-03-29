LIBNAME := push_swap.a
NAME := push_swap
FLAGS := -Wall -Wextra -Werror
FILES := 
OBJ_FILES := $(FILES:.c=.o)
LIBFT := libft
all: $(NAME)

a:
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(LIBNAME)
clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ_FILES)
fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)
re: fclean all

obj:
	cc $(FLAGS) -c $(FILES)
$(NAME): obj a
	ar -rcs $(LIBNAME) $(OBJ_FILES)

