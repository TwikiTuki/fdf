NAME=fdf
PPF=-Wall -Werror -Wextra
SRCS=fdf_utils.c fdf_lines.c  fdf_matrices.c fdf_points.c fdf_initial_transforms.c fdf_events.c
OBJS_DIR=./objs/
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
SRCS_DIR=./srcs
HEADERS=$(SRCS_DIR)/fdf.h
NAME=fdf

MAIN=fdf.c 
MAIN_DIR=./$(SRCS_DIR)/
OUT_FILE=./$(NAME)


all: $(NAME)

prnt:
	@ echo OBJS_DIR: $(OBJS_DIR)
	@ echo OBJS: $(OBJS)
	@ echo SRCS_DIR: $(SRCS_DIR)
	@ echo OBJS_DIR: $(OBJS_DIR)/fdf_utils.o

$(NAME): $(OBJS) $(MAIN_DIR)$(MAIN)
	make -Clibft MAKEOVERRIDES=
	$(CC) $(PPF) -I ../ $(OBJS) $(MAIN_DIR)$(MAIN) -Llibft -lft -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit  -o$(OUT_FILE)

$(OBJS_DIR)%.o: $(SRCS_DIR)/%.c $(HEADERS)
	mkdir -p $(OBJS_DIR)
	$(CC) $(PPF) -c $< -o $@	

clean:
	make -C libft fclean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
