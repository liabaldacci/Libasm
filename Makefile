# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 19:41:24 by gadoglio          #+#    #+#              #
#    Updated: 2021/05/19 20:33:12 by gadoglio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

CC		=	nasm

C_FLAGS =  -g -no-pie -Werror -Wextra -Wall

FLAGS	=	-f elf64

SRCS	=	ft_strlen.s ft_read.s ft_write.s ft_strcpy.s \
			ft_strcmp.s ft_strdup.s 
			
TESTERS = 	tester_ft_read.c tester_ft_strcmp.c tester_ft_strcpy.c \
			tester_ft_strdup.c tester_ft_strlen.c tester_ft_write.c

OBJS	=	$(patsubst %.s, %.o, ${SRCS}) 

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

%.o: %.s
			$(CC) $(FLAGS) -o $@ $<

clean	:
			rm -f $(OBJS)
			rm -f ./tester

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

retest	:	fclean test

test	:	all main.c
			clang $(C_FLAGS) $(TESTERS) main.c -L./ -lasm -I ./libasm.h -o tester
			./tester

.PHONY	:	all re clean fclean test
