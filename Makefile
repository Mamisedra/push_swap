NAME	= push_swap
LIBFT_DIR	= ./ft_libft
PRINTF_DIR	= ./ft_printf
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf
SRCS	= mandatory/swap.c mandatory/show_target.c mandatory/show_cost.c mandatory/reverse.c mandatory/reverse_reverse.c \
		mandatory/push.c mandatory/push_swap.c mandatory/push_swap_utils.c mandatory/push_list.c mandatory/push_clear.c \
		mandatory/make_list.c mandatory/main.c mandatory/list_params.c mandatory/list_params_utils.c mandatory/algorithm.c \
		mandatory/place_top.c mandatory/push_clear_utils.c mandatory/ft_lis.c mandatory/ft_lis_utils.c mandatory/all.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

extern: printf libft

printf:
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)/libftprintf.a ./

libft:
	@make -C ${LIBFT_DIR}
	@cp $(LIBFT_DIR)/libft.a ./

$(NAME): extern $(OBJS)
	@$(CC) $(FLAGS) $(SRCS) libftprintf.a libft.a -o $(NAME)

clean:
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@$(RM) ${OBJS}

fclean: clean
	@$(RM) $(NAME) libft.a libftprintf.a ${LIBFT_DIR}/libft.a ${PRINTF_DIR}/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
