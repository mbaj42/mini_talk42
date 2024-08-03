SRCS =	ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	p_specifier.c \
	id_specifier.c \
	u_specifier.c \
	small_x_specifier.c \
	large_x_specifier.c \


OBJS = $(SRCS:.c=.o)

CC = clang
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME) 
re: fclean all

.PHONY: all clean fclean re
