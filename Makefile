##
## Makefile for zappy in /home/dupard_e/rendus/PSU_2015_zappy
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Sat Jun  4 17:39:33 2016 Erwan Dupard
## Last update Mon Jun 20 17:52:39 2016 Barthelemy Gouby
##

CC		= gcc

RM		= rm -f

CLIENT_NAME	= zappy_ai
SERVER_NAME	= zappy_server
GRAPHIC_NAME	= console

CLIENT_BINARY	= zappy_ai
SERVER_BINARY	= zappy_server
GRAPHIC_BINARY	= console

CLIENT_SRCS	= client_src/main.c				\
		  client_src/connect.c				\
		  client_src/parser.c				\
		  client_src/request.c				\
		  client_src/request2.c				\
		  client_src/request3.c				\
		  client_src/ai.c				\
		  client_src/map.c				\
		  client_src/list_fct.c				\
		  client_src/buf.c				\
		  utils/circular_buffer/circular_buffer.c	\
		  utils/circular_buffer/circular_buffer2.c	\

GRAPHIC_SRCS	= graphic_src/main.c				\
		  graphic_src/network.c 			\
		  graphic_src/xsocket.c 			\
		  graphic_src/xconnect.c 			\
		  graphic_src/xclose.c 				\
		  graphic_src/client.c				\
		  graphic_src/my_strdup.c			\
		  graphic_src/FCT/fct_welcome.c 		\
		  graphic_src/FCT/fct_msz.c 			\
		  graphic_src/FCT/fct_bct.c 			\
		  graphic_src/FCT/fct_tna.c 			\
		  graphic_src/FCT/fct_pnw.c 			\
		  graphic_src/FCT/fct_ppo.c 			\
		  graphic_src/FCT/fct_plv.c 			\
		  graphic_src/FCT/fct_pin.c 			\
		  graphic_src/FCT/fct_pex.c 			\
		  graphic_src/FCT/fct_pbc.c 			\
		  graphic_src/FCT/fct_pic.c 			\
		  graphic_src/FCT/fct_pie.c 			\
		  graphic_src/FCT/fct_pfk.c 			\
		  graphic_src/FCT/fct_pdr.c 			\
		  graphic_src/FCT/fct_pgt.c 			\
		  graphic_src/FCT/fct_pdi.c 			\
		  graphic_src/FCT/fct_enw.c 			\
		  graphic_src/FCT/fct_eht.c 			\
		  graphic_src/FCT/fct_ebo.c 			\
		  graphic_src/FCT/fct_ebi.c 			\
		  graphic_src/FCT/fct_sgt.c 			\
		  graphic_src/FCT/fct_seg.c 			\
		  graphic_src/FCT/fct_smg.c 			\
		  graphic_src/FCT/fct_suc.c 			\
		  graphic_src/FCT/fct_sbp.c 			\
		  graphic_src/get_next_line.c			\
		  utils/circular_buffer/circular_buffer.c	\
		  utils/circular_buffer/circular_buffer2.c	\
		  utils/my_str_to_wordtab/my_str_to_wordtab.c 	\
		  utils/my_str_to_wordtab/my_str_to_wordtab2.c 	\

SERVER_SRCS	= server_src/main.c				\
		  server_src/options.c				\
		  server_src/options_id.c			\
		  server_src/options_id2.c			\
		  server_src/map.c				\
		  server_src/map2.c				\
		  server_src/process.c				\
		  server_src/commands_handle.c			\
		  server_src/graphic.c				\
		  server_src/graphic_commands.c			\
		  server_src/graphic_commands2.c		\
		  server_src/drone_commands.c			\
		  server_src/drone_commands2.c			\
		  server_src/drone_commands3.c			\
		  server_src/client_identification.c		\
		  server_src/events.c		 		\
		  server_src/events2.c		 		\
		  server_src/events3.c		 		\
		  server_src/events4.c				\
		  server_src/trigger_event.c		 	\
		  server_src/event_handling.c			\
		  server_src/action.c				\
		  server_src/food.c				\
		  server_src/voir.c				\
		  server_src/incantations.c			\
		  server_src/egg.c				\
		  utils/circular_buffer/circular_buffer.c	\
		  utils/circular_buffer/circular_buffer2.c	\

CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)
SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
GRAPHIC_OBJS	= $(GRAPHIC_SRCS:.c=.o)

CFLAGS		+= -g3 -W -Wall -Werror -Wextra -pedantic -ansi -I./utils

LDFLAGS		+=

all: $(CLIENT_NAME) $(SERVER_NAME) $(GRAPHIC_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) -o $(CLIENT_BINARY) $(CLIENT_OBJS) $(CFLAGS) $(LDFLAGS)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) -o $(SERVER_BINARY) $(SERVER_OBJS) $(CFLAGS) $(LDFLAGS)

$(GRAPHIC_NAME): $(GRAPHIC_OBJS)
	$(CC) -o $(GRAPHIC_BINARY) $(GRAPHIC_OBJS) $(CFLAGS) $(LDFLAGS) -lm

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
