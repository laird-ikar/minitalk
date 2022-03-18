# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 17:29:03 by bguyot            #+#    #+#              #
#    Updated: 2022/03/18 14:00:28 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minitalk
SERVER				= server
CLIENT				= client

INCLUDE				= ./includes/
LIBFT				= ./libft/
DIR_CLIENT			= ./src_client/
DIR_SERVER			= ./src_server/

FILES_CLIENT		= client.c
FILES_SERVER		= server.c

SRC_CLIENT			= $(addprefix $(DIR_CLIENT),$(FILES_CLIENT))
OBJ_CLIENT			= $(SRC_CLIENT:.c=.o)
SRC_SERVER			= $(addprefix $(DIR_SERVER),$(FILES_SERVER))
OBJ_SERVER			= $(SRC_SERVER:.c=.o)

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
RM					= rm -f
LIBS				= -Llibft -lft

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(LIBS) $(OBJ_CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(LIBS) $(OBJ_SERVER)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(CLIENT) $(SERVER)

re:	fclean all

.PHONY:	all clean fclean re
