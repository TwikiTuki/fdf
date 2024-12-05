all:
	cd ft_printf && make
	cp ./ft_printf/libftprintf.a ./libft.a 
	make -C ./get_next_line

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
