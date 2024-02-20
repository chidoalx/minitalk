CC = cc

CFLAGS = -Wall -Wextra -Werror

B_DIR = minitalk_bonus

SRCS = client.c server.c ft_putchar_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_atoi.c

SRCS_BONUS = $(B_DIR)/client_bonus.c \
	$(B_DIR)/server_bonus.c \
	$(B_DIR)/ft_putchar_fd.c \
	$(B_DIR)/ft_putnbr_fd.c \
	$(B_DIR)/ft_putstr_fd.c \
	$(B_DIR)/ft_atoi.c\

NAME = server
NAME2 = client
NAME_BONUS = server_bonus
NAME2_BONUS = client_bonus

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME) $(NAME2)

bonus: $(NAME_BONUS) $(NAME2_BONUS)

$(NAME): server.o ft_putchar_fd.o ft_putnbr_fd.o ft_putstr_fd.o 
	$(CC) -g -fsanitize=address $(CFLAGS) $^ -o $@

$(NAME2): client.o ft_putchar_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_atoi.o 
	$(CC) -g -fsanitize=address $(CFLAGS) $^ -o $@

$(NAME_BONUS): $(B_DIR)/server_bonus.o $(B_DIR)/ft_putchar_fd.o $(B_DIR)/ft_putnbr_fd.o $(B_DIR)/ft_putstr_fd.o 
	$(CC) $(CFLAGS) $^ -o $@

$(NAME2_BONUS): $(B_DIR)/client_bonus.o $(B_DIR)/ft_putchar_fd.o $(B_DIR)/ft_putnbr_fd.o $(B_DIR)/ft_putstr_fd.o $(B_DIR)/ft_atoi.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME2) $(NAME_BONUS) $(NAME2_BONUS)

re: fclean all
