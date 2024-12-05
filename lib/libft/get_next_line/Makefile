NAME=../libft.a
CPPFLAGS=-Wall -Werror -Wextra
#OBJS=get_next_line_bonus.o get_next_line_utils_bonus.o
OBJS=get_next_line.o get_next_line_utils.o

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%o: %c Makefile get_next_line.h
	$(CC) $(CPPFLAGS) -c $(<) -o $(@)
clean:
	rm -f $(OBJS)
fclean: clean

.PHONY: $(NAME) clean fclean
