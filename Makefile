# Program name
NAME = libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Directories
SRCDIR = src
INCDIR = include
LIBFTDIR = libft
OBJDIR = obj

# Source files
SRCFILES = ft_printf.c
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Include paths
INCLUDES = -I$(INCDIR) -I$(LIBFTDIR)

# Libft
LIBFT = $(LIBFTDIR)/libft.a

# Default target
all: $(NAME)

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
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
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

# Clean everything
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re