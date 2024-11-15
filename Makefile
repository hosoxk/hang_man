#project name and compilation settings
NAME = hang_man
CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
MAKEFLAGS += -s

#directories
SRC_DIR = ./sources
LIBFT_DIR = ./include/libft

#source and object files
SRC_FILES = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/generate_word.c

OBJ_FILES = $(SRC_FILES:.c=.o)

#libraries
LIBFT = $(LIBFT_DIR)/libft.a

#define colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

#build targets
all: $(LIBFT) $(NAME)

#link executables
$(NAME): $(OBJ_FILES) $(LIBFT)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compilation successfull!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	rm -fr $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing $(NAME) executable...$(RESET)"
	rm -fr $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Executable $(NAME) removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
