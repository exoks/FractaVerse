# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 21:14:18 by oezzaou           #+#    #+#              #
#    Updated: 2023/01/28 21:49:11 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################
#           Compiler               #
####################################
CC = gcc
CFLAGS =
# THIS FLAGS USED FROM THE LINKDER IT'S MUST BE USED WHEN LINKING OBJECTS
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

####################################
#              SRCS                #
####################################
NAME = fractol
OBJDIR = obj
SRCDIR = src
INC = include
SRCS = main
OBJS := $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))
SRCS := $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRCS)))

#####################################
#              RULES                #
#####################################

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -rf $(NAME)

.PHONEY: all clean fclean re
