# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 11:31:59 by emilgarc          #+#    #+#              #
#    Updated: 2025/02/06 19:08:38 by emilgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = ../../obj
STATIC_DIR = ../../staticlibs

SOURCES =\
	get_next_line_bonus.c\
	get_next_line_utils_bonus.c

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

.PHONY: all bonus clean fclean re