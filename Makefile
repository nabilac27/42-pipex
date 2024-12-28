# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 00:12:49 by nchairun          #+#    #+#              #
#    Updated: 2024/12/28 06:48:59 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Static Library name
NAME	= pipex

# Compiler and Linker
CC 		= cc

# Compiler  flags
CFLAGS	= -Wall -Wextra -Werror

# Source files (.c files)
SRCS	= ./pipex.c

# Object files (generated from source files)
OBJS	= $(SRCS:.c=.o)

# Default target to create static library
all		= $(NAME)

# Rule to create static library from object files
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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

# Exeutable binary
#  is a compiled program that your computer can directly 
#  human-readable source code (like .c files in C) 
# is converted into machine-readable instructions (binary code) 
# that the operating system can execute.