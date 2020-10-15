# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 16:42:33 by rgarcia-          #+#    #+#              #
#    Updated: 2020/09/15 16:59:51 by rgarcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

SRCS	=	ft_printf.c				\
			ft_hard_mode.c			\
			ft_special.c			\
			ft_type.c				\
			ft_int.c				\
			ft_int_extra.c			\
			ft_unsigned.c			\
			ft_unsigned_extra.c		\
			ft_str.c				\
			ft_str_extra.c			\
			ft_char.c				\
			ft_pointer.c			\
			ft_pointer_extra.c		\
			ft_hexa.c				\
			ft_percent.c			\
			ft_extra_functions_1.c	\
			ft_extra_functions_2.c	\
			ft_extra_functions_3.c	\

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		@ar -rcs $(NAME) $(OBJS)

%.o:%.c		$(HEADER)
		@gcc -Wall -Wextra -Werror -o $@ -c $< -I $(HEADER)

clean	:
		@/bin/rm -f $(OBJS)

fclean	:	clean
		@/bin/rm -f $(NAME)

re		:	fclean all