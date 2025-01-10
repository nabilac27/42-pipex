# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 05:36:37 by nchairun          #+#    #+#              #
#    Updated: 2025/01/10 19:21:52 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC 		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./libft/ft_split.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
