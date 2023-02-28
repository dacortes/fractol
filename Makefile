# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 12:21:24 by dacortes          #+#    #+#              #
#    Updated: 2023/02/28 09:27:59 by dacortes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== VARIABLES ================================== #

NAME = fractol
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -O3

# =========================== SOURCES ======================================== #

SRC = check_arg.c colors.c events.c exit.c init_var.c main.c render.c reset_var.c\
	status_btn.c\
	menu/render_mn.c menu/txt_sets.c\
	sets/mandelbrot.c sets/julia.c sets/Burning_ship.c
LIBFT = ./libft/
MINIL = ./miniLibX/
L_SRC = ./src
L_LIB = ./libft/libft.a
L_MLX = ./miniLibX/libmlx.a
L_FRAME = -framework OpenGL -framework AppKit
INC			=	-I ./inc/\
				-I ./libft/\
				-I ./minilibX/

# =========================== DIRECTORIES ==================================== #

D_OBJ = $(L_SRC)/obj
#.o
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

# =========================== BOLD COLORS ==================================== #

E = \033[m
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
#Font
ligth = \033[1m
dark = \033[2m
italic = \033[3m

# ========================== MAKE RULES ===================================== #
#Rules
all: dir $(NAME)
-include $(DEP)
dir:
	@make bonus -C $(LIBFT)
	@make -C $(MINIL)
	@mkdir -p $(D_OBJ)
	@mkdir -p $(D_OBJ)/sets
	@mkdir -p $(D_OBJ)/menu
$(D_OBJ)/%.o:$(L_SRC)/%.c
	@printf "$(ligth)$(Y)\r$@...$(E)"
	@$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(L_LIB) $(L_MLX) $(L_FRAME) -o $(NAME) $(INC)
	@echo  "\n$(B)$(ligth)-->$(G) ==== Project fractol compiled! ==== ✅$(E)"

# ========================== CLEAN   ===================================== #

.PHONY: clean fclean re
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(B)$(ligth)-->$(E)$(ligth) ==== fractol object files cleaned! ==== ✅$(E)"
clean:
	@$(RM) $(D_OBJ)
	@make clean -C $(LIBFT)
	@make clean -C $(MINIL)
	@echo "$(B)$(ligth)-->$(E)$(ligth) ==== fractol executable files and name cleaned! ==== ✅$(E)"
re: fclean all
