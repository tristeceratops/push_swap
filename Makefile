NAME := push_swap
FLAGS := -Wall -Wextra -Werror
FILES := lis.c main.c main_utils.c operators.c operators_next.c sort.c utils.c utils_next.c sort_utils.c sort_utils_next.c mov_a.c sort_5.c
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
