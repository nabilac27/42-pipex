# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 00:12:49 by nchairun          #+#    #+#              #
#    Updated: 2024/12/27 00:30:29 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Static Library name
NAME	= pipex.a

# Compiler and Linker
CC 		= cc

# Compiler  flags
CFLAGS	= -Wall -Wextra -Werror

# Archiver tool (to create static library)
AR		= ar rcs
# Source files (.c files)
SRCS	= ./pipex.c

# Object files (generated from source files)
OBJS	= $(SRCS:.c=.o)

# Default target to create static library
all		= $(NAME)

# Rule to create static library from object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $^

# Rule to compile .c files into .o files
%.o = %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove.o files and static library
clean:
		rm -f $(OBJS)

# 
fclean: clean
		rm -f $(NAME)

re: fclean all

# Phony targets (not actual files)
.PHONY: all clean fclean re


# Makefile
# is a script used by the make tool to automate the process of compiling, 
# linking, and managing dependencies in software projects. 

# Static library
# is a collection of object files bundled together into a single .a or .lib file.