SRCS = client.c server.c

OBJS = $(SRCS:.c=.o)

CC = clang
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client

LIBFT_DIR = libft
PRINTF_DIR = printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a


all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): server.o $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT): client.o $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^

server.o: server.c mini_talk.h
	$(CC) $(CFLAGS) -c $< -o $@

client.o: client.c mini_talk.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f server.o client.o
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
