##
## Makefile for zappy in /home/dupard_e/rendus/PSU_2015_zappy
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Sat Jun  4 17:39:33 2016 Erwan Dupard
## Last update Tue Jun  7 16:18:05 2016 Erwan Dupard
##

CC		= gcc

RM		= rm -f

CLIENT_NAME	= client
SERVER_NAME	= server
GRAPHIC_NAME	= graphic

CLIENT_BINARY	= bin/client
SERVER_BINARY	= bin/server
GRAPHIC_BINARY	= bin/console

CLIENT_SRCS	= client_src/main.c
GRAPHIC_SRCS	= graphic_src/main.c

SERVER_SRCS	= server_src/main.c		\
		  server_src/options.c		\
		  server_src/options_id.c	\
		  server_src/options_id2.c	\

CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)
SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
GRAPHIC_OBJS	= $(GRAPHIC_SRCS:.c=.o)

CFLAGS		+= -W -Wall -Werror -Wextra -pedantic -ansi

LDFLAGS		+=

all: $(CLIENT_NAME) $(SERVER_NAME) $(GPRAHIC_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) -o $(CLIENT_BINARY) $(CLIENT_OBJS) $(CFLAGS) $(LDFLAGS)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) -o $(SERVER_BINARY) $(SERVER_OBJS) $(CFLAGS) $(LDFLAGS)

$(GRAPHIC_NAME): $(GRAPHIC_OBJS)
	$(CC) -o $(GRAPHIC_BINARY) $(GRAPHIC_OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(CLIENT_OBJS)
	$(RM) $(SERVER_OBJS)
	$(RM) $(GRAPHIC_OBJS)

fclean: clean
	$(RM) $(CLIENT_BINARY)
	$(RM) $(SERVER_BINARY)
	$(RM) $(GRAPHIC_BINARY)

re: fclean all

.PHONY: all clean fclean re
