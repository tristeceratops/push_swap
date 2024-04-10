NAME := push_swap
FLAGS := -Wall -Wextra -Werror
FILES := lis.c main.c operators.c operators_next.c sort.c utils.c
all: $(NAME)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ_FILES)
fclean: clean
	make fclean -C $(name)
	rm -f $(NAME)
re: fclean all

$(NAME):
	cc $(FLAGS) $(FILES) libft/*.c libft/*.h -o $(NAME)
