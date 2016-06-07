NAME = client

SRCS = main.c \
	   parser.c

OBJS = $(SRCS:.c=.o)

all:	$(OBJS)
	gcc $(OBJS) -o $(NAME) -W -Wall -Wextra

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
