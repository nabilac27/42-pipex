# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 05:36:37 by nchairun          #+#    #+#              #
#    Updated: 2025/01/19 02:09:42 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC 		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./pipex.c ./utils.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= ./libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME)

re: fclean all

$(LIBFT):
	make -C ./libft

.PHONY: all clean fclean re $(LIBFT)
