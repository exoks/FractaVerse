# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 21:14:18 by oezzaou           #+#    #+#              #
#    Updated: 2023/01/29 17:19:09 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################
#           Compiler               #
####################################
CC = gcc
CFLAGS =
# THIS FLAGS USED FROM THE LINKDER IT'S MUST BE USED WHEN LINKING OBJECTS
MLX_FLAGS = -framework OpenGL -framework AppKit

####################################
#              SRCS                #
####################################
NAME = fractol
OBJDIR = obj
SRCDIR = src
INC = include
MLXLIB = libmlx.a
SRCS = test
OBJS := $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))
SRCS := $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRCS)))

#####################################
#              RULES                #
#####################################

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $(INC)/$(MLXLIB) $^ -o $@ $(MLX_FLAGS)

$(OBJDIR):
	mkdir -p $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

re: fclean all

test: 
	./$(NAME)
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -rf $(NAME)

.PHONEY: all clean fclean re
