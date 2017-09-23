NAME = lem-in

CC= gcc -o
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
LIBFTPRINTF= src/ft_printf/libftprintf.a

SRC = src/main src/printing src/validation src/initial \
		src/parsing src/addition src/other src/delete \
		src/get_some_data src/checking src/identification \
		src/finding_path src/writing src/create_ant_list

OBJ = $(addsuffix .o,$(SRC))

all: lib ft_printf lem-in

lib:
	@make -C ./libft

ft_printf:
	@make -C ./src/ft_printf

lem-in: $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(LIBFTPRINTF)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $< 

clean:
	@make -C libft clean
	@make -C ./src/ft_printf clean
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFTPRINTF)
	@rm -f $(LIBFT)
	@rm -f ./visualize/lem-in.txt

re: fclean all
