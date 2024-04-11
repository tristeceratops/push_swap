NAME := push_swap
FLAGS := -Wall -Wextra -Werror
FILES := lis.c main.c operators.c operators_next.c sort.c utils.c utils_next.c
OBJ := $(FILES:.c=.o)
LIBFT := libft/
LIBFT_LIB := libft.a

all: $(NAME)

$(NAME): $(OBJ) do_libft
	cc $(FLAGS) $(OBJ) -L$(LIBFT) -lft -o $@

%.o: %.c
	cc $(FLAGS) -c $< -o $@

do_libft:
	make -C $(LIBFT)
	make bonus -C $(LIBFT)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
