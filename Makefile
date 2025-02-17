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
CC				= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

#====<[ Colors: ]>==============================================================
GREEN			:= \033[1;32m
RED				:= \033[1;31m
CYAN			:= \033[1;36m
NOCLR			:= \033[1;0m

#====<[ Sources: ]>=============================================================
NAME				:= fractol
NAME_BONUS	:= fractol_bonus
OBJDIR			:= obj
SRCDIR			:= src
BDIR				:= bonus
INC 				= -I include/ -I ft_printf/include -I ft_printf/libft

#====<[ Mondatory: ]>===========================================================
SRCS := fractol fractol_menu fractol_window fractals fractol_events fractol_utils
OBJS := $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))
SRCS := $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRCS)))

#====<[ Bonus Sources: ]>=======================================================
SRCB := burning_ship_fractal fractals_bonus fractol_events_bonus \
				fractol_menu_bonus
OBJB := $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCB)))
SRCB := $(addprefix $(SRCDIR)/$(BDIR)/, $(addsuffix .c, $(SRCB)))

PREQ := fractol fractol_window fractol_utils
OPREQ := $(addprefix $(OBJDIR)/, $(addsuffix .o, $(PREQ)))
PREQ := $(addprefix $(SRCDIR)/, $(addsuffix .c, $(PREQ)))

LIBFTPRINTF = ft_printf/libftprintf.a

#====<[ Rules: ]>==============================================================
all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF) 
	@$(CC) $(CFLAGS) $(INC) $^ -o $@ $(MLX_FLAGS)
	@printf "\n%10s===========%10s\n <<<<<<<<<< $(GREEN)$(NAME)$(NOCLR) >>>>>>>>>>\n" " " " "
	@printf "%10s===========%10s\n" " " " "

bonus: $(OBJDIR) $(NAME_BONUS) 

$(NAME_BONUS): $(OBJB) $(OPREQ) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(INC) $^ -o $@ $(MLX_FLAGS)
	@printf "\n%10s===========%10s\n <<<<<<< $(GREEN)$(NAME_BONUS)$(NOCLR) >>>>>>>\n" " " " "
	@printf "%10s===========%10s\n" " " " "

$(LIBFTPRINTF):
	@make -C ft_printf

$(OBJDIR):
	@echo "Creating >>>>>>>>>>> OBJDIR ..."
	@mkdir -p $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "Creating >>>>>>>>>>> $@ ..."

$(OBJDIR)/%.o: $(SRCDIR)/$(BDIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "Creating >>>>>>>>>>> $@ ..."

re: fclean all

clean:
	@rm -rf $(OBJDIR)
	@make -C ft_printf/ clean
	@echo "Cleaning OBJECTS >>>>>>>> ... -=> Done"

fclean: clean
	@make -C ft_printf/ fclean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "Cleaning $(NAME) >>>>>>>> ... -=> Done"

.PHONY: all clean fclean re
#==============================================================================
