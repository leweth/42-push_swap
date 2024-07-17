CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = push_swap.c utils/ft_atoi.c utils/ft_memcpy.c utils/linked_lists_utils.c utils/validate_input.c \
		utils/ft_isdigit.c utils/ft_split.c

OBJS = ${SRCS:.c=.o}

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $< -o $@


all: printf $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;33mBuilding Target...\033[0m"
	${CC} ${CFLAGS} $(OBJS) lib/printf/libftprintf.a -o ${NAME}
	@echo "\033[1;32mTarget Built Successfully!\033[0m"

printf:
	@echo "\033[1;33mBuilding printf...\033[0m"
	make -C lib/printf

clean:
	@echo "\033[1;33mRemoving Object files...\033[0m"
	make -C lib/printf clean
	rm ${OBJS}

fclean: clean
	@echo "\033[1;33mRemoving libraries and program...\033[0m"
	rm ${NAME}
	make -C lib/printf fclean

re: fclean all

test:
	${CC} ${CFLAGS} tests/main_test.c utils/linked_lists_utils.c utils/ft_split.c utils/ft_memcpy.c -o run