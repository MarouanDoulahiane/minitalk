SRC-C	=	client.c utilis.c 
SRC-S	=	server.c utilis.c

SRC-C-B	=	client_bonus.c utilis.c
SRC-S-B	=	server_bonus.c utilis.c

CC		=	cc -Wall -Werror -Wextra

NAME-C	=	client
NAME-S	=	server

NAME-C-B	=	client_bonus
NAME-S-B	=	server_bonus

RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
NC		=	\033[0m

all:	$(NAME-C) $(NAME-S)

bonus:	$(NAME-C-B) $(NAME-S-B)

$(NAME-C): minitalk.h client.c utilis.c 
		@$(CC) $(SRC-C) -o $(NAME-C) 
		@echo "$(GREEN)Client program was created$(NC)"

$(NAME-S): minitalk.h server.c utilis.c
		@$(CC) $(SRC-S) -o $(NAME-S) 
		@echo "$(GREEN)Server program was created$(NC)"

$(NAME-C-B): minitalk.h client_bonus.c utilis.c
		@$(CC) $(SRC-C-B) -o $(NAME-C-B) 
		@echo "$(GREEN)Client bonus program was created$(NC)"

$(NAME-S-B): minitalk.h server_bonus.c utilis.c
		@$(CC) $(SRC-S-B) -o $(NAME-S-B)  
		@echo "$(GREEN)Server bonus program was created$(NC)"

clean:
		@rm -fr $(NAME-C) $(NAME-S) $(NAME-C-B) $(NAME-S-B)
		@echo "$(RED)You delete everything$(NC)"

fclean:	clean

re:		fclean all

.PHONY:	all clean fclean re