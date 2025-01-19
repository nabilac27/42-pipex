# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 19:29:29 by nchairun          #+#    #+#              #
#    Updated: 2025/01/10 19:34:04 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc

CFLAGS 	= -Wall -Wextra -Werror

AR 		= ar rcs

SRCS 	=	./ft_split.c	./ft_strchr.c	./ft_strdup.c	./ft_strjoin.c	\
			./ft_strlcpy.c	./ft_strlen.c	./ft_strncmp.c

OBJS 	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean 
