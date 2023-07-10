SRC = 	main.c   \
		init.c   \
		status.c \
		dinner.c \
		tools.c
		
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAG = -Wall -Wextra -Werror  -fsanitize=thread -g
RM = rm -rf
NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -pthread -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re