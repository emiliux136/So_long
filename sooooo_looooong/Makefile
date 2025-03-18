# Project: so_long

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -Wunreachable-code -Ofast
RM          = rm -rf

# =================== DIRECTORIES =================== #
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR		= include/
LIBFT_DIR   = lib/libft
GNL_DIR     = lib/gnl
PRINTF_DIR  = lib/printf
LIBMLX      = lib/MLX42
INCLUDE     = -I ./include -I $(LIBMLX)/include/

# =================== LIBRARIES =================== #
LIBS        = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT       = $(INC_DIR)/libft.a
GNL         = $(INC_DIR)/gnl.a
PRINTF      = $(INC_DIR)/printf.a
ALL_LIBS	= $(LIBS) $(LIBFT) $(GNL) $(PRINTF)
# =================== SOURCE FILES =================== #
SRC         = $(shell find $(SRC_DIR) -name '*.c')
OBJ         = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# =================== COLORS =================== #
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
RESET       = \033[0m

# =================== REGLAS =================== #
all: libmlx libft printf gnl $(NAME)

$(NAME): $(OBJ)
	@$(CC) -v $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(PRINTF) $(ALL_LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) creado con éxito!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(BLUE)Compilando: $(notdir $<)$(RESET)"

libmlx:
	@echo "$(YELLOW)Compilando MLX42...$(RESET)"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo "$(YELLOW)Compilando libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

printf:
	@echo "$(YELLOW)Compilando printf...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)

gnl:
	@echo "$(YELLOW)Compilando get_next_line...$(RESET)"
	@$(MAKE) -C $(GNL_DIR)

clean:
	@echo "$(RED)Limpiando objetos...$(RESET)"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	@echo "$(RED)Eliminando ejecutable...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(RM) $(LIBMLX)/build
	@$(RM) $(INC_DIR)

re: fclean all

.PHONY: all clean fclean re libmlx libft printf gnl