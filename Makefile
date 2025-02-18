# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 21:14:18 by oezzaou           #+#    #+#              #
#    Updated: 2023/02/22 23:08:17 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#====<[ MLX & Compiler: ]>======================================================
CC					:= cc
CFLAGS			:= -Wall -Wextra -Werror
MLX_FLAGS 	:= -lmlx -framework OpenGL -framework AppKit

#====<[ Colors: ]>==============================================================
GREEN				:= \033[1;32m
RED					:= \033[1;31m
CYAN				:= \033[1;36m
NOCLR				:= \033[1;0m

#====<[ Sources: ]>=============================================================
NAME				:= fractol
NAME_BNS		:= fractol_bonus
OBJ_DIR			:= obj
SRC_DIR			:= src
BNS_DIR			:= bonus
INCLUDE 		:= -Iinclude/ -Ift_printf/include -Ift_printf/libft

#====<[ Mondatory: ]>===========================================================
SRC 				:= fractol fractol_menu fractol_window fractals fractol_events \
							 fractol_utils

OBJ 				:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))
SRC 				:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

#====<[ Bonus Sources: ]>=======================================================
SRC_BNS				:= burning_ship_fractal fractals_bonus fractol_events_bonus \
							 fractol_menu_bonus

OBJ_BNS			:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_BNS)))
SRC_BNS			:= $(addprefix $(SRC_DIR)/$(BNS_DIR)/, $(addsuffix .c, $(SRC_BNS)))

UTILS				:= fractol fractol_window fractol_utils
OBJ_UTILS		:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(UTILS)))
UTILS				:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(UTILS)))

LIBFTPRINTF := ft_printf/libftprintf.a

#====<[ Rules: ]>==============================================================
all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF) 
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@ $(MLX_FLAGS)
	@printf "\n%10s===========%10s\n <<<<<<<<<< $(GREEN)$(NAME)$(NOCLR) >>>>>>>>>>\n" " " " "
	@printf "%10s===========%10s\n" " " " "

bonus: $(OBJ_DIR) $(NAME_BNS) 

$(NAME_BNS): $(OBJ_BNS) $(OBJ_UTILS) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@ $(MLX_FLAGS)
	@printf "\n%10s===========%10s\n <<<<<<< $(GREEN)$(NAME_BNS)$(NOCLR) >>>>>>>\n" " " " "
	@printf "%10s===========%10s\n" " " " "

$(LIBFTPRINTF):
	@make -C ft_printf

$(OBJ_DIR):
	@echo "Creating >>>>>>>>>>> OBJ_DIR ..."
	@mkdir -p $@
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Creating >>>>>>>>>>> $@ ..."

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(BNS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Creating >>>>>>>>>>> $@ ..."

re: fclean all

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ft_printf/ clean
	@echo "Cleaning OBJECTS >>>>>>>> ... -=> Done"

fclean: clean
	@make -C ft_printf/ fclean
	@rm -rf $(NAME) $(NAME_BNS)
	@echo "Cleaning $(NAME) >>>>>>>> ... -=> Done"

.PHONY: all clean fclean re
#==============================================================================
