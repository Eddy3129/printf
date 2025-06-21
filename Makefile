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

# Colors for output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Default target
all: $(NAME)

# Create object directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft
$(LIBFT):
	@echo "$(CYAN)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFTDIR)

# Create the library
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREEN)Creating $(NAME)...$(RESET)"
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re