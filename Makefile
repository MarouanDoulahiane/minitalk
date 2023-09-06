CC = cc -W -W -W 

CLIENT_C = client.c
SERVER_C = server.c

CLIENT = client
SERVER = server

LIBFT_DIR = ft_printf
LIBFT = ft_printf/libft.a

MAKE = make -C $(LIBFT_DIR)
MAKE_FCLEAN = make fclean -C $(LIBFT_DIR)
MAKE_CLEAN = make clean -C $(LIBFT_DIR)

#Colors:
RED		=	\033[1;31m
GREEN	=	\033[1;32m
END		=	\033[0m

_SUCCESS	=	$(GREEN)[SUCCESS]$(END)
_INFO	=	$(RED)[INFO]$(END)

all: $(LIBFT) $(CLIENT) $(SERVER) 

$(LIBFT):
	@$(MAKE)

$(SERVER): $(CLIENT)
	@$(CC) $(SERVER_C) $(LIBFT) -o $(SERVER)
	@printf "$(_SUCCESS) $(SERVER) ready.\n"

$(CLIENT):
	@$(CC) $(CLIENT_C) $(LIBFT) -o $(CLIENT)
	@printf "$(_SUCCESS) $(CLIENT) ready.\n"

fclean:
	@$(MAKE_FCLEAN)
	@rm -fr $(SERVER) $(CLIENT)
	@printf "$(_INFO) $(CLIENT) removed.\n"
	@printf "$(_INFO) $(SERVER) removed.\n"

clean:
	@$(MAKE_CLEAN)
	@printf "$(_INFO)object files removed.\n"

re: fclean all