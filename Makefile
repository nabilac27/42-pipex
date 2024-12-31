# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefle                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 05:36:37 by nchairun          #+#    #+#              #
#    Updated: 2024/12/31 05:39:14 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./pipex.c

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
