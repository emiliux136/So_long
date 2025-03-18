# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 11:31:59 by emilgarc          #+#    #+#              #
#    Updated: 2025/03/18 14:42:14 by emilgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = ../../obj
STATIC_DIR = ../../include

SOURCES = \
	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memset.c\
	ft_memcmp.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_split.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_substr.c\
	ft_strtrim.c\
	ft_strrchr.c\
	ft_strchr.c\
	ft_strnstr.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c

OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(STATIC_DIR)/$(NAME)

$(STATIC_DIR)/$(NAME): $(OBJECTS)
	@mkdir -p $(STATIC_DIR)  
	$(AR) -r $@ $?
	
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re