# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 17:29:03 by bguyot            #+#    #+#              #
#    Updated: 2023/04/28 10:52:44 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minitalk
SERVER				= server
CLIENT				= client
LIBFT				= libs/libft/libft.a

SRCS_SERVER			= srcs/server.c
SRCS_CLIENT			= srcs/client.c
INCS_SERVER			= incs/server.h
INCS_CLIENT			= incs/client.h

OBJS_SERVER			= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT			= $(SRCS_CLIENT:.c=.o)

CC					= @gcc
CFLAGS				= -Wall -Wextra -Werror
RM					= @rm -f

all:		$(NAME)

$(NAME):	$(SERVER) $(CLIENT)

$(SERVER):	$(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT):	$(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT)

$(OBJS_SERVER):	$(INCS_SERVER) $(SRCS_SERVER)
	$(CC) $(CFLAGS) -c $(SRCS_SERVER) -o $(OBJS_SERVER)

$(OBJS_CLIENT):	$(INCS_CLIENT) $(SRCS_CLIENT)
	$(CC) $(CFLAGS) -c $(SRCS_CLIENT) -o $(OBJS_CLIENT)

$(LIBFT):
	@make -C libs/libft

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@make fclean -C libs/libft

fclean:		clean
	$(RM) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re