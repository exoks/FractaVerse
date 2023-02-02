# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:55:24 by oezzaou           #+#    #+#              #
#    Updated: 2023/01/30 16:51:32 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := libftprintf.a
SRCDIR := src/
OBJDIR := obj/
INC = -I libft -I include/
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := ft_manage_flags.c ft_putnbr_base_upx.c ft_print_char.c ft_print_str.c ft_putnbr_base_id.c ft_printf_utils.c
OBJ := ${SRC:.c=.o}
SRC := $(addprefix $(SRCDIR), $(SRC))
OBJ := $(addprefix $(OBJDIR), $(OBJ))
LIBFT = libft/

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) -c ft_printf.c -o $(OBJDIR)ft_printf.o
	@ar -crs $@ $(LIBFT)*.o $(OBJDIR)*.o
	@echo "Creating >>>>>>>>>> LIBFTPRINTF ... Done"

$(LIBFT):
	@make -C $@	

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus: clean $(NAME)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@rm -rf $(OBJDIR) 

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@rm -rf $(OBJDIR) $(NAME)
	@echo "Cleaning LIBFTPRINTF >>>>>>> ... -=> Done"

re: fclean all
	
.PHONY: test all clean fclean re bonus $(LIBFT)
