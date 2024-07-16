CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = push_swap.c

OBJS = ${SRCS:.c=.o}


%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $< -o $@


all: $(PRINTF) $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;33mBuilding Target...\033[0m"
	${CC} ${CFLAGS} $(OBJS) -o ${NAME}
	@echo "\033[1;32mTarget Built Successfully!\033[0m"

$(PRINTF):
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
	${CC} ${CFLAGS} tests/main_test.c utils/linked_lists_utils.c -o run