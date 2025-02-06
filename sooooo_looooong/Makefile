# Project: so_long

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
LFLAGS 		= -ldl -lglfw -pthread -lm
RM          = rm -rf

# //=================== DIRECTORIES ===================// #

INCLUDE     = includes
SRC_DIR     = .
LIBFT_DIR   = source/libft
GNL_DIR		= source/gnl
PRINTF_DIR	= source/printf
OBJ_DIR     = obj
LIBMLX		= MLX42
LIBMLX42 = ./MLX42/build/libmlx42.a
LIBFT_SRC   = $(LIBFT_DIR)
PRINTF_SRC  = $(PRINTF_DIR)
GETNEXTLINE_SRC  = $(GNL_DIR)

# //=================== LIB ===================// #

LIB			= lib/
LIB_DIR		= ./lib/
LIBS		= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -L./$(LIBFT) -lft
MLX_FLAGS	= -L$(MLX_DIR)/include -lglfw -ldl -pthread -lm
MLX_DIR 	= $(LIB_DIR)$(LIBMLX)
LIBMLX		= MLX42

APP			= ./a.out

# //=================== FILES ===================// #

HEADERS		= -I ./include -I $(LIBMLX)/include -I ${LIBFT_DIR} -I ${GNL_DIR} -I ${PRINTF_DIR}
LIBS		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRC_FILES   = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_SRC)/*.c) $(wildcard $(PRINTF_SRC)/*.c) $(wildcard $(GETNEXTLINE_SRC)/*.c)
OBJ_FILES   = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))



# //=================== COLORS ===================// #

RED         = \033[1;31m
GREEN       = \033[1;32m
BLUE        = \033[1;34m
YELLOW      = \033[1;33m
RESET       = \033[0m

# //=================== REGLAS ===================// #

all: libmlx libft printf get_next_line $(NAME)

libmlx:
	@echo "$(YELLOW)Compilando la biblioteca MLX42...$(RESET)"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo "$(YELLOW)Compilando libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

printf:
	@echo "$(YELLOW)Compilando printf...$(RESET)"
	@$(MAKE) -C $(PRINTF_SRC)

get_next_line:
	@echo "$(YELLOW)Compilando get_next_line...$(RESET)"
	@$(MAKE) -C $(GETNEXTLINE_SRC)

$(NAME): $(OBJ_FILES)
	@echo "$(YELLOW)Creación de $(NAME)...$(RESET)"
	@$(CC) $(OBJ_FILES) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)$(NAME) creado con éxito! $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compilacion de $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	@echo "$(RED)Eliminando los objetos... $(RESET)"
	@$(RM) $(OBJ_DIR) $(LIBMLX)/build
	@echo "$(RED)Eliminando MLX42$(RESET)"
	@${MAKE} -C ${LIBMLX} clean
	@echo "$(RED)Eliminando libft$(RESET)"
	@${MAKE} -C ${LIBFT} clean
	@echo "$(RED)Eliminando printf$(RESET)"
	@${MAKE} -C ${PRINTF_DIR} clean
	@echo "$(RED)Eliminando get_next_line$(RESET)"
	@${MAKE} -C ${GNL_DIR} clean

fclean: clean
	@echo "$(RED)Eliminando los objetos... $(RESET)"
	@$(RM) $(OBJ_DIR) $(LIBMLX)/build
	@echo "$(RED)Eliminando MLX42$(RESET)"
	@${MAKE} -C ${LIBMLX} fclean
	@echo "$(RED)Eliminando libft$(RESET)"
	@${MAKE} -C ${LIBFT} fclean
	@echo "$(RED)Eliminando printf$(RESET)"
	@${MAKE} -C ${PRINTF_DIR} fclean
	@echo "$(RED)Eliminando get_next_line$(RESET)"
	@${MAKE} -C ${GNL_DIR} fclean

re: fclean all

.PHONY: all clean fclean re libmlx