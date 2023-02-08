#Colors
E = \033[m
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
#Font
ligth = \033[1m
dark = \033[2m
italic = \033[3m
#Variables
NAME = fractol
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror
SRC = main.c utils.c errors.c fractols.c colors.c mouse.c 
L_SRC = ./src
L_LIB = ./libft/libft.a
L_MLX = ./miniLibX/libmlx.a
L_FRAME = -framework OpenGL -framework AppKit
D_OBJ = $(L_SRC)/obj
#.o
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))
#Rules
all: dir $(NAME)
-include $(DEP)
dir:
	@mkdir -p $(D_OBJ)
$(D_OBJ)/%.o:$(L_SRC)/%.c
	$(CC) -MMD $(FLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(L_LIB) $(L_MLX) $(L_FRAME) -o $(NAME)
	@echo -e "$(B)$(ligth)-->$(G)$(NAME) created OK$(E)"
.PHONY: clean fclean re
fclean: clean
	$(RM) $(NAME)
	@echo -e "$(B)$(ligth)-->$(E)$(ligth)Full clean: $(Y)*.a$(E)"
clean:
	$(RM) $(D_OBJ)
	@echo -e "$(B)$(ligth)-->$(E)$(ligth)Clean: $(Y)*.o$(E)"
re: fclean all
