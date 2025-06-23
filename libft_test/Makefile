# Mandatory source files
SRCS_MANDATORY = ft_atoi.c \
                ft_bzero.c \
                ft_calloc.c \
                ft_memchr.c \
                ft_memcmp.c \
                ft_memcpy.c \
                ft_memmove.c \
                ft_strdup.c \
                ft_strjoin.c \
                ft_strlcat.c \
                ft_strlcpy.c \
                ft_strlen.c \
                ft_strnstr.c \
                ft_substr.c \
                ft_isalpha.c \
                ft_isdigit.c \
                ft_isalnum.c \
                ft_isascii.c \
                ft_isprint.c \
                ft_memset.c \
                ft_toupper.c \
                ft_tolower.c \
                ft_strchr.c \
                ft_strrchr.c \
                ft_strncmp.c \
                ft_strtrim.c \
                ft_split.c \
                ft_itoa.c \
                ft_strmapi.c \
                ft_striteri.c \
                ft_putchar_fd.c \
                ft_putstr_fd.c \
                ft_putendl_fd.c \
                ft_putnbr_fd.c

# Bonus source files
SRCS_BONUS =  ft_lstnew.c \
              ft_lstadd_front.c \
              ft_lstsize.c \
              ft_lstlast.c \
              ft_lstadd_back.c \
              ft_lstdelone.c \
              ft_lstclear.c \
              ft_lstiter.c \
              ft_lstmap.c

# Object files
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Compiler and tools
CC = gcc
AR = ar
RM = rm -f

# Flags
CFLAGS = -Wall -Wextra -Werror -I.
ARFLAGS = rcs

# Library name
NAME = libft.a

# Default target: builds the library with mandatory functions
all: $(NAME)

# Rule to build the library with mandatory functions
# This target means "the file $(NAME) depends on $(OBJS_MANDATORY)"
$(NAME): $(OBJS_MANDATORY)
	@echo "Archiving mandatory functions into $(NAME)..."
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_MANDATORY)
	@echo "$(NAME) with mandatory functions is ready."

# Rule to compile .c files to .o files (generic pattern rule)
# This rule will be used to build any .o file from its .c source
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus target: compiles bonus functions and adds them to the library
# It depends on 'all' to ensure the library with mandatory functions exists first,
# and on $(OBJS_BONUS) to ensure bonus object files are compiled.
bonus: all $(OBJS_BONUS)
	@echo "Adding bonus functions to $(NAME)..."
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)
	@echo "Bonus functions added to $(NAME)."

# Clean object files
clean:
	@echo "Cleaning object files..."
	$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@echo "Object files cleaned."

# Clean object files and the library
fclean: clean
	@echo "Cleaning $(NAME)..."
	$(RM) $(NAME)
	@echo "$(NAME) cleaned."

# Rebuild everything (mandatory and bonus)
re: fclean all bonus

# Rule to build the test executable (if you have one, otherwise remove this section)
# TEST_NAME = test_libft
# TEST_SRCS = test_main.c # Example test source file
# TEST_OBJS = $(TEST_SRCS:.c=.o)
# $(TEST_NAME): $(TEST_OBJS) $(NAME)
#	$(CC) $(CFLAGS) $(TEST_OBJS) -L. -lft -o $(TEST_NAME)

# Phony targets (targets that are not files)
.PHONY: all bonus clean fclean re