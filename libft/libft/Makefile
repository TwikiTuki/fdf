
SRCS =	ft_atoi.c		ft_isascii.c    ft_memcmp.c     ft_strchr.c     ft_strncmp.c    ft_toupper.c 	\
		ft_bzero.c		ft_isdigit.c    ft_memcpy.c     ft_strlcat.c    ft_strnstr.c       				\
		ft_isalnum.c	ft_isprint.c    ft_memmove.c    ft_strlcpy.c    ft_strrchr.c 	ft_calloc.c		\
		ft_isalpha.c	ft_memchr.c     ft_memset.c     ft_strlen.c     ft_tolower.c	ft_strdup.c 	\
		ft_strtrim.c	ft_split.c		ft_itoa.c		ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	\
		ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_strjoin.c 	ft_substr.c 

BONUS_SRCS =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	\
				ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c

NAME = libft.a

OBJS = $(SRCS:.c=.o)  

DEPS = $(SRCS:.c=.d)

BONUS = .bonus

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

BONUS_DEPS = $(BONUS_SRCS:.c=.d)

INCLUDE = -I ./

WFLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus: $(BONUS)

%.o: %.c 
	$(CC) -MMD $(INCLUDE) $(WFLAGS) -c $< -o $@ 

$(NAME): $(OBJS) 
	ar -rcs $(NAME) $(OBJS)
	
-include $(DEPS)

$(BONUS): $(OBJS) $(BONUS_OBJS)
	touch $@
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

-include $(BONUS_DEPS)

clean:
	@-rm -f $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS)

fclean: clean
	@-rm -f $(NAME) $(BONUS)

re: fclean all


variables:
	@echo SRCS $(SRCS)
	echo
	@echo OBJS $(OBJS)
	echo
	@echo DEPS $(DEPS)
	echo
	@echo BONUS_SRCS $(BONUS_SRCS)
	echo
	@echo BONUS_OBJS $(BONUS_OBJS)
	echo
	@echo BONUS_DEPS $(BONUS_DEPS)
.PHONY: clean fclean all re bonus
