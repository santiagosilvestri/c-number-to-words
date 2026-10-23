NAME = numwords
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c src/conversion.c src/conversion_scale.c \
       src/dictionary.c src/dictionary_parse.c src/dictionary_read.c \
       src/number_validate.c src/word_join.c src/output.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT): $(wildcard libft/*.c libft/*.h) libft/Makefile
	$(MAKE) -C libft fclean
	$(MAKE) -C libft CC="$(CC)" CFLAGS="$(CFLAGS)"

%.o: %.c include/numwords.h libft/libft.h
	$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
