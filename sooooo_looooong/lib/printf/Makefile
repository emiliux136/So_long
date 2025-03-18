# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 19:07:21 by emilgarc          #+#    #+#              #
#    Updated: 2025/03/18 13:11:32 by emilgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = ../../obj
STATIC_DIR = ../../include

SOURCES =\
	ft_printf.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putnbr.c\
	ft_unsigned.c\
	ft_putptr.c\
	ft_hexa.c

OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(STATIC_DIR)/$(NAME)

$(STATIC_DIR)/$(NAME): $(OBJECTS)
	@mkdir -p $(STATIC_DIR)  
	$(AR) -r $@ $?

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

PHONY: all clean fclean re