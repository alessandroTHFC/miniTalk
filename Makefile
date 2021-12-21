CFLAGS = -Wall -Werror -Wextra
CC = gcc

SERVER = server
CLIENT = client
MSERVER = server.c
MCLIENT = client.c
BSERVER = bonus/serverBonus.c
BCLIENT = bonus/clientBonus.c

INC = includes
PRINTF = myPrintf
FLAGS = -Wall -Wextra -Werror -I$(INC) -I$(PRINTF)/Includes -L$(PRINTF) -lftprintf

all:
	@make -s -C $(PRINTF)
	@gcc $(FLAGS) src/$(BSERVER) -o $(SERVER)
	@gcc $(FLAGS) src/$(BCLIENT) -o $(CLIENT)
	@echo --Server Ready--
	@echo --Client Ready--

m: 
	@make -s -C $(PRINTF)
	@gcc $(FLAGS) src/server.c -o $(SERVER)
	@gcc $(FLAGS) src/client.c -o $(CLIENT)
	@echo --Server Ready--
	@echo --Client Ready--

bonus: 
	make -s -C $(PRINTF)
	gcc $(FLAGS) src/$(BSERVER) -o $(SERVER)
	gcc $(FLAGS) src/$(BCLIENT) -o $(CLIENT)
	@echo --Server Ready--
	@echo --Client Ready--

clean:
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo --Clean As A Whistle--

re: fclean all
