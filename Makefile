# Names of the executables
NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

# Directories
SRC_DIR = src
FT_PRINTF_DIR = ft_printf
INCLUDE_DIR = include

# Source files
SRC_CLIENT = $(SRC_DIR)/client.c
SRC_SERVER = $(SRC_DIR)/server.c
SRC_CLIENT_BONUS = $(SRC_DIR)/client_bonus.c
SRC_SERVER_BONUS = $(SRC_DIR)/server_bonus.c

FT_PRINTF_SRC = $(FT_PRINTF_DIR)/convert_base.c \
                $(FT_PRINTF_DIR)/ft_printf.c \
                $(FT_PRINTF_DIR)/print_hex.c \
                $(FT_PRINTF_DIR)/print_number.c \
                $(FT_PRINTF_DIR)/print_str.c

# Object files
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

OBJ_FT_PRINTF = $(FT_PRINTF_SRC:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

# Default rule
all: $(NAME_CLIENT) $(NAME_SERVER)

# Link client and server with ft_printf objects
$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(OBJ_FT_PRINTF)

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(OBJ_FT_PRINTF)

# Bonus rule
bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(OBJ_FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJ_CLIENT_BONUS) $(OBJ_FT_PRINTF)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(OBJ_FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJ_SERVER_BONUS) $(OBJ_FT_PRINTF)

# Compile object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF_DIR)/%.o: $(FT_PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS) $(OBJ_FT_PRINTF)

# Clean object files and executables
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus


