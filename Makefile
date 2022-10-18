# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 19:57:49 by ppanpais          #+#    #+#              #
#    Updated: 2022/10/14 17:42:09 by ppanpais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRC_PATH	=	srcs/
SRC_FILES	=	pf_get_data.c pf_print_bhex.c pf_print_data.c pf_printptr.c \
				pf_print_shex.c pf_putchar.c pf_putnbr.c pf_putstr.c \
				pf_putuint.c pf_get_str.c
SRCS		=	$(foreach f, $(SRC_FILES), $(SRC_PATH)$(f)) ft_printf.c
LIBFT		=	libft.a
LIBFT_PATH	=	libft/
OBJ_PATH	=	objs/
OBJS		=	$(SRC_FILES:.c=.o) ft_printf.o
//OBJS		=	$(foreach f, $(OBJ_FILES), $(OBJ_PATH)$(f))
CC		=	gcc
CFLAGS		=	-g -c -Wall -Werror -Wextra

all:		$(NAME)
$(NAME):	$(OBJS) $(LIBFT)
			cp $(LIBFT_PATH)$(LIBFT) $(NAME)
			ar -rcs $(NAME) $(OBJS)
$(OBJS):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS)
$(LIBFT):
			make -C libft/ bonus
clean:
			rm -f $(OBJS)
			make -C libft/ clean
fclean: 	clean
			rm -f $(NAME)
			make -C libft/ fclean
re:		fclean all
