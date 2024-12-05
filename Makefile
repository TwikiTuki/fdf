CC=gcc
NAME=fdf
PPF=-Wall -Werror -Wextra
SRCS=fdf_utils.c fdf_lines.c  fdf_matrices.c fdf_points.c fdf_initial_transforms.c fdf_events.c
OBJS_DIR=./objs/
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
SRCS_DIR=./srcs
HEADERS=$(SRCS_DIR)/fdf.h
NAME=fdf

LIB=lib/
LIBFT_DIR=$(LIB)libft/
MINILIB_DIR=$(LIB)minilibx_linux/

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
	make -C$(LIBFT_DIR) MAKEOVERRIDES=
	make -C$(MINILIB_DIR) MAKEOVERRIDES= 
	$(CC) $(PPF) -I  $(LIBFT_DIR) -I $(MINILIB_DIR) $(OBJS) $(MAIN_DIR)$(MAIN) -L$(LIBFT_DIR) -lft -L$(MINILIB_DIR) -lmlx -lXext -lX11 -lm -o$(OUT_FILE)

$(OBJS_DIR)%.o: $(SRCS_DIR)/%.c $(HEADERS)
	mkdir -p $(OBJS_DIR)
	$(CC) $(PPF) -I  $(LIBFT_DIR) -I $(MINILIB_DIR) -c $< -o $@	

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(MINILIB_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

deps:
	apt-get update && apt-get -y install xorg libxext-dev zlib1g-dev libbsd-dev

.PHONY: all clean fclean re
