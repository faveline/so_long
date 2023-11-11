NAME = so_long

NAME_BONUS = so_long_bonus

SOURCES = ft_action_on_hook.c	\
		  ft_action_utils.c		\
		  ft_check_map.c		\
		  ft_check_map_utils.c	\
		  ft_creat_map.c		\
		  ft_error.c			\
		  ft_init_window.c		\
		  ft_utils.c			\
		  ft_main.c

SOURCES_LIBFT = ft_printf.c				\
				ft_printf_char.c		\
				ft_printf_decimal.c		\
				ft_printf_hexa_lower.c	\
				ft_printf_hexa_upper.c	\
				ft_printf_int.c			\
				ft_printf_point.c		\
				ft_printf_string.c		\
				ft_printf_uns_dec.c		\
				ft_putnbr_fd.c			\
				ft_itoa.c				\
				get_next_line.c			\
				get_next_line_utils.c

SOURCES_BONUS = ft_action_on_hook.c		\
				ft_action_utils.c		\
				ft_animation.c			\
				ft_check_map.c			\
				ft_check_map_utils.c	\
				ft_creat_map.c			\
				ft_error.c				\
				ft_init_window.c		\
				ft_main.c				\
				ft_patrol.c				\
				ft_print_screen_bonus.c	\
				ft_redraw_patrol.c		\
				ft_utils.c				

LIBFT = $(addprefix libft/, $(SOURCES_LIBFT))

BONUS = $(addprefix bonus/, $(SOURCES_BONUS))

MLX42 = MLX42/build/libmlx42.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX42_FLAGS = -ldl -lglfw -pthread -lm
RM = rm -f

all : $(NAME)

$(NAME): 
	$(CC) $(SOURCES) $(LIBFT) $(MLX42) $(CFLAGS) $(MLX42_FLAGS) -o $(NAME)

bonus :
	$(CC) $(BONUS) $(LIBFT) $(MLX42) $(CFLAGS) $(MLX42_FLAGS) -o $(NAME_BONUS)

clean :

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY:	all clean fclean re bonus
