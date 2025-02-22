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
GREEN					= \033[1;32m
RED						= \033[1;31m
BLUE					= \033[34m
CYAN					= \033[1;36m
GRAY					= \033[0;90m
PURPLE				= \033[0;35m
YELLOW				= \033[0;93m
BLACK  				= \033[20m
MAGENTA 			= \033[35m
WHITE  				= \033[37m
PINK					= \033[0;38;5;199m
ORANGE 				= \033[38;5;214m
LIGHT_BLACK  	= \033[90m
LIGHT_RED    	= \033[91m
LIGHT_GREEN  	= \033[92m
LIGHT_YELLOW 	= \033[93m
LIGHT_BLUE   	= \033[94m
LIGHT_MAGENTA = \033[95m
LIGHT_CYAN   	= \033[96m
LIGHT_WHITE  	= \033[97m
LIGHT_BLUE		= \033[38;5;45m
RESET					= \033[1;0m

#====<[ Sources: ]>=============================================================
PROJECT			:= fract-ol
NAME				:= fractol
NAME_BNS		:= fractol_bonus
FT_PRINTF		:= ft_printf
OBJ_DIR			:= obj
SRC_DIR			:= src
BNS_DIR			:= bonus
RM					:= rm -rf
INCLUDE 		:= -Iinclude/ -I$(FT_PRINTF)/include -I$(FT_PRINTF)/libft/include

#====<[ Mondatory: ]>===========================================================
SRC 				:= fractol fractol_menu fractol_window fractals fractol_events \
							 fractol_utils

OBJ 				:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))
SRC 				:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

#====<[ Bonus: ]>===============================================================
SRC_BNS				:= burning_ship_fractal fractals_bonus fractol_events_bonus \
							 fractol_menu_bonus

OBJ_BNS			:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_BNS)))
SRC_BNS			:= $(addprefix $(SRC_DIR)/$(BNS_DIR)/, $(addsuffix .c, $(SRC_BNS)))

UTILS				:= fractol fractol_window fractol_utils
OBJ_UTILS		:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(UTILS)))
UTILS				:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(UTILS)))

LIBFTPRINTF := $(FT_PRINTF)/libftprintf.a

#====<[ Rules: ]>==============================================================
all: $(OBJ_DIR) $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJ) 
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@ $(MLX_FLAGS)
	@echo "${GREEN}[OK]: ${CYAN}$(NAME) ✔️${RESET}"

bonus: $(OBJ_DIR) $(NAME_BNS) 

$(NAME_BNS): $(LIBFTPRINTF) $(OBJ_BNS) $(OBJ_UTILS) 
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@ $(MLX_FLAGS)
	@echo "${GREEN}[OK]: ${CYAN}$(NAME_BNS) ✔️${RESET}"

$(LIBFTPRINTF):
	@make -C $(FT_PRINTF)

$(OBJ_DIR):
	@mkdir -p $@
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET}: ${PINK}Compiling${RESET} %-33s| $@\n" "$<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(BNS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET}: ${PINK}Compiling${RESET} %-33s| $@\n" "$<"

re: fclean all

clean:
	@make -C $(FT_PRINTF) fclean
	@if [ -d $(OBJ_DIR) ]; then\
		${RM} $(OBJ_DIR);\
		printf "${GREEN}[OK]${RESET}: ${ORANGE}Cleaning  %-33s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(OBJ_DIR) ✔️";\
	else\
		printf "${RED}[KO]${RESET}: ${BLUE}Not Found %-33s${RESET}| ./%s\n"\
					 "..." "$(PROJECT)/$(OBJ_DIR) ✖️";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		${RM} $(NAME);\
		printf "${GREEN}[OK]${RESET}: ${ORANGE}Cleaning  %-33s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(NAME) ✔️";\
	fi
	@if [ -f $(NAME_BNS) ]; then\
		${RM} $(NAME_BNS);\
		printf "${GREEN}[OK]${RESET}: ${ORANGE}Cleaning  %-33s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(NAME_BNS) ✔️";\
	fi

.PHONY: all clean fclean re
#==============================================================================
