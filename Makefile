# Program name
NAME = libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Directories
LIBFTDIR = libft

# Source files (directly in root)
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

# Include paths
INCLUDES = -I. -I$(LIBFTDIR)

# Libft
LIBFT = $(LIBFTDIR)/libft.a

# Default target
all: $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

# Create the library
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

# Clean object files
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

# Clean everything
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re