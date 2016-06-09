NAME = client

SRCS = main.c \
	   parser.c \
	   request.c \
	   request2.c \
	   request3.c \
	   connect.c

OBJS = $(SRCS:.c=.o)

CFLAGS += -W -Wall -Wextra -ansi -pedantic

all:	$(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
