# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 19:41:24 by gadoglio          #+#    #+#              #
#    Updated: 2021/05/12 20:29:55 by gadoglio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

CC		=	nasm

FLAGS	=	-f elf64

SRCS	=	ft_strlen.s ft_read.s ft_write.s ft_strcpy.s \
			ft_strcmp.s ft_strdup.s

OBJS	=	$(patsubst %.s, %.o, ${SRCS}) 

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo "\033[0mUpdating library..."
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
			@echo "\033[0m"

%.o: %.s
			@echo "\033[0mGenerating Lib..."
			$(CC) $(FLAGS) -o $@ $<
			@echo "\033[0m"

clean	:	
			@echo "\033[0mCleaning objects..."
			rm -f $(OBJS)
			rm -f ./tester
			@echo "\033[0m"

fclean	:	clean
			@echo "\033[0mCleaning objects and library..."
			rm -f $(NAME)
			@echo "\033[0m"

re		:	fclean all

test	:	all main.c
			clang -g -no-pie -Werror -Wextra -Wall main.c -L./ -lasm -I ./libasm.h -o tester

.PHONY	:	all re clean fclean test
