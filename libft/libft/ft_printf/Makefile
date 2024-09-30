NAME=libftprintf.a
OBJS_ND_DEPS=./objs_nd_deps/
SRC=ft_flchars.c ft_flnums.c ft_printf.c
OBJS=$(addprefix $(OBJS_ND_DEPS), $(SRC:.c=.o))
DEPS=$(addprefix $(BJS_ND_DEPS), $(SRC:.c=.d))
LIBFT_DIR=../libft/
WSF=-Wall -Werror -Wextra

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)*
	cd $(LIBFT_DIR) && make && cp libft.a ../ft_printf/$(NAME)
	ar -rc $(@) $(OBJS)

$(LIBFT_DIR)%: ;

$(OBJS_ND_DEPS)%.o: %.c ft_printf.h Makefile
	mkdir -p $(OBJS_ND_DEPS)
	$(CC) -MMD $(WSF) -c -o$@ $<

clean:
	@ -rm -fr $(OBJS_ND_DEPS)
#	make -C $(LIBFT_DIR) clean

fclean: clean
	@ -rm -f $(NAME)
#	make -C $(LIBFT_DIR) fclean

re: fclean all 

.PHONY: all re clean fclean
