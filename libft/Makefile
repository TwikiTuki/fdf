NC=\033[0;0m
RED=\033[0;31m
CYAN=\033[0;36m
all:
	@ echo "$(CYAN) making library $(NC)"
	@ echo "$(CYAN) making ft_printf and libft $(NC)"
	echo "MAKEOVERRIDES = $(MAKEOVERRIDES)"
	echo "PPF = $(PPF)"
	cd ft_printf && make
	cp ./ft_printf/libftprintf.a ./libft.a 
	@ echo "$(CYAN) making get_next_line $(NC)"
	make -C ./get_next_line
	@ echo "$(CYAN) Made library $(NC)"

clean:
	make -C libft clean
	make -C ft_printf clean
	make -C get_next_line clean
	
fclean: clean
	@-rm -f libft.a
	make -C libft fclean
	make -C ft_printf fclean
	make -C get_next_line fclean

re: fcelan all

.PHONY: all clean fclean re
