# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 17:29:03 by bguyot            #+#    #+#              #
#    Updated: 2023/04/28 11:01:25 by bguyot           ###   ########.fr        #
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

OBJ_COLOR		=		"\e[38;5;147m"
CLN_COLOR		=		"\e[38;5;124m"
BIN_COLOR		=		"\e[38;5;129m"
ERRASE_LINE		=		"\e[2K\r"

all:		$(NAME)

$(NAME):	$(SERVER) $(CLIENT)

$(SERVER):	$(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(SERVER)
	@printf $(ERRASE_LINE)$(BIN_COLOR)"\t"$(SERVER)"\t\t\t\t[ ✓ ]\n\e[0m"

$(CLIENT):	$(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT)
	@printf $(ERRASE_LINE)$(BIN_COLOR)"\t"$(CLIENT)"\t\t\t\t[ ✓ ]\n\e[0m"

.c.o:	$(INCS_SERVER) $(INCS_CLIENT)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(ERRASE_LINE)$(OBJ_COLOR)"\t"$@"\e[0m"

$(LIBFT):
	@make -C libs/libft

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" objects\t\t[ ✓ ]\n\e[0m"
	@make fclean -C libs/libft

fclean:		clean
	$(RM) $(SERVER) $(CLIENT)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" binary\t\t[ ✓ ]\n\e[0m"

re:			fclean all

.PHONY:		all clean fclean re