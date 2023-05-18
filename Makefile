
# Name of the program
NAME = push_swap

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g
# FSANITIZE = -fsanitize=address -g3
FSANITIZE =


# Folders
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/

# Source files and object files
SRC_FILES = main.c libft_fct.c ft_atoi.c push_swap_reverse.c quicksort.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))


# all rule
all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) $(FSANITIZE) -I $(INC_DIR) -o $@ -c $<

# Compiling
$(NAME): $(OBJ)
	@echo "...Compiling... Wait a sec."
	@gcc $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "$(NAME) generated!".

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@echo "Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re