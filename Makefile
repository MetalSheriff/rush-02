# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obritany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 20:25:08 by obritany          #+#    #+#              #
#    Updated: 2020/09/27 20:28:58 by obritany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush_02
HEADER	= includes
SRCS	= main.c make_dict.c functions.c read_dict.c parse_num.c print_control.c
OBJS	= $(SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror
RM 		= rm -f

.c.o:
			gcc -c $(CFLAGS) -I $(HEADER) $< -o $(<:.c=.o)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

$(NAME):	$(OBJS)
			gcc $(OBJS) -o $(NAME)

.PHONY: all clean fclean re
