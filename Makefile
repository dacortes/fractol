# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 12:21:24 by dacortes          #+#    #+#              #
#    Updated: 2023/02/08 12:32:56 by dacortes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== VARIABLES ================================== #

NAME = fractol
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror

# =========================== SOURCES ======================================== #

SRC = main.c utils.c errors.c fractols.c colors.c mouse.c 
LIBFT = ./libft/
L_SRC = ./src
L_LIB = ./libft/libft.a
L_MLX = ./miniLibX/libmlx.a
L_FRAME = -framework OpenGL -framework AppKit

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
	@mkdir -p $(D_OBJ)
$(D_OBJ)/%.o:$(L_SRC)/%.c
	@printf "$(ligth)$(Y)\r $@$(E)"
	@$(CC) -MMD $(FLAGS) -c $< -o $@
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(L_LIB) $(L_MLX) $(L_FRAME) -o $(NAME)
	@echo -e "\n$(B)$(ligth)-->$(G) ==== Project fractol compiled! ==== ✅$(E)"

# ========================== CLEAN   ===================================== #

.PHONY: clean fclean re
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo -e "$(B)$(ligth)-->$(E)$(ligth) ==== fractol object files cleaned! ==== ✅$(E)"
clean:
	@$(RM) $(D_OBJ)
	@make clean -C $(LIBFT)
	@echo -e "$(B)$(ligth)-->$(E)$(ligth) ==== fractol executable files and name cleaned! ==== ✅$(E)"
re: fclean all
