NAME = libftprintf.a
LIBFT = libft.a
LIBFTFOLDER = libft/
FLAGS = -Wall -Werror -Wextra -g
HEADER = ft_printf.h

SRCS = ft_printf.c \
		ft_utils1.c \
		ft_parser.c \
		ft_print_format.c \
		ft_printf_num.c \
		ft_printf_string.c \
		ft_printf_pointer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTFOLDER)
	cp $(LIBFTFOLDER)$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@

clean_printf:
	rm -f $(OBJS)

fclean_printf:
	rm -f $(NAME)

clean_libft:
	$(MAKE) -C $(LIBFTFOLDER) clean

fclean_libft:
	$(MAKE) -C $(LIBFTFOLDER) fclean

clean: clean_printf clean_libft

fclean: clean fclean_printf fclean_libft

re: fclean all
