# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 19:57:49 by ppanpais          #+#    #+#              #
#    Updated: 2022/10/07 20:35:18 by ppanpais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRC_PATH	=	srcs/
SRC_FILES	=	pf_printHex.c pf_printptr.c
LIBFT		=	libft.a
OBJS_PATH	=	objs/
OBJS		=	
all:	$(NAME)
$(NAME):	