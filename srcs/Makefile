# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaulet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 06:29:39 by fchanal           #+#    #+#              #
#    Updated: 2017/06/10 15:53:40 by fchanal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
###                  Settings                 ###
#################################################

NAME = libftprintf.a
CC = clang
FLAGS = -Wall -Wextra -Werror
SRC_PATH = ./srcs/
INC_PATH = -I./includes/

#################################################
###                  Colors                   ###
#################################################

COL_BLACK  = \033[1;30m
COL_RED    = \033[1;31m
COL_GREEN  = \033[1;32m
COL_YELLOW = \033[1;33m
COL_BLUE   = \033[1;34m
COL_PURPLE = \033[1;35m
COL_WHITE  = \033[1;37m

#################################################
###                 Sources                   ###
#################################################

SRC =\
	\
	 ft_all.c \
	 ft_fun_nb.c \
	 ft_function_test.c \
	 ft_printf.c \
	 conv/conv_all_base.c \
	 ini_all.c \
	 \
	 flags/ft_all_bases.c \
	 flags/print_flags.c \
	 flags/print_autre.c \
	 \
	 parce/parce.c \
	 parce/parce_fc.c \
	 parce/ignor.c \
	 parce/switch.c \
	 \
	 type_data/ft_init_type.c \
	 type_data/ft_type_data.c \
	 type_data/init_spec.c \
	 \
	 unicode/ft_uni_C.c \
	 unicode/handle_three_bytes.c \
	 unicode/grand_spec.c

#################################################
###                   Format                  ###
#################################################

SRCS = $(addprefix $(SRC_PATH), $(SRC))
O = $(notdir $(SRC))
OB = $(basename $(O))
OBJ = $(addsuffix .o ,$(OB))

#################################################
###                   Rules                   ###
#################################################

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ): $(SRCS)
	$(CC) -c $(FLAGS) $(INC_PATH) $(SRCS)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
