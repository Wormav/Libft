CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

# Couleurs pour le terminal
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

# Emojis
SUCCESS_EMOJI = ✅
CLEAN_EMOJI = 🗑️

# Répertoires
OBJ_DIR = obj/
SRC_DIR = ./
PRINTF_DIR = ft_printf/

# Fichiers de la libft
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	  ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
	  ft_strdup.c ft_calloc.c ft_strtrim.c ft_substr.c \
	  ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c \

# Fichiers bonus de la libft
SRCB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	   ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	   ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	   ft_lstmap_bonus.c \

# Fichiers du projet ft_printf
PRINTF_SRC = ft_printf/src/decimal_convert.c ft_printf/src/ft_printf.c \
             ft_printf/src/string_convert.c

# Objets
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJB = $(addprefix $(OBJ_DIR), $(SRCB:.c=.o))
PRINTF_OBJ = $(addprefix $(OBJ_DIR), $(notdir $(PRINTF_SRC:.c=.o)))

# Headers
HEADER = libft.h

# Cible principale
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(PRINTF_OBJ) $(OBJB)
	@if [ ! -f $(NAME) ] || [ "$(OBJ) $(PRINTF_OBJ) $(OBJB)" -nt "$(NAME)" ]; then \
		ar rcs $(NAME) $(OBJ) $(PRINTF_OBJ) $(OBJB); \
		echo "$(GREEN)$(SUCCESS_EMOJI) Compilation réussie : $(NAME)$(RESET)"; \
	fi

# Compilation des fichiers objets
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF_DIR)src/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(CLEAN_EMOJI) Fichiers objets supprimés$(RESET)"

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(CLEAN_EMOJI) $(NAME) supprimé$(RESET)"

# Reconstruction
re: fclean all

.PHONY: all clean fclean re
