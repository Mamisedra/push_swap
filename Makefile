NAME	= push_swap
LIBFT_DIR	= ./ft_libft
PRINTF_DIR	= ./ft_printf
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf
SRCS	= mandatory/check_arg.c mandatory/argc_to_list.c \
		mandatory/main.c mandatory/make_list.c mandatory/push_utils.c
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
	@$(CC) $(FLAGS) $(OBJS) libftprintf.a libft.a -o $(NAME)

clean:
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@$(RM) ${OBJS}

fclean: clean
	@$(RM) $(NAME) libft.a libftprintf.a ${LIBFT_DIR}/libft.a ${PRINTF_DIR}/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
