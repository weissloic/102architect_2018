##
## EPITECH PROJECT, 2018
## finalstumper
## File description:
## Makefile
##

CC	=	gcc -g

CFLAGS	=	-W -Wextra -Wall
CINC	=   -I include/
LDFLAGS =   -Llib/my -lmy

NAME	=	102architect

NAME_TEST = unit_tests

MAIN	=	main.c

RED     = \033[0;31m
YELLOW  = \033[1;33m
CYAN    = \033[0;36m
GOLD    = \033[0;33m
GREEN   = \033[0;32m
BLUE	= \033[0;34m
NC	    = \033[0;0m

PREFIX	=	$(CYAN)"[MAIN] "

all:	$(NAME)

$(NAME):
		@echo "$(GREEN)[LIB] $(BLUE)Compiling...$(NC)"
		@make -sC lib/my
		@echo "$(PREFIX)$(BLUE)Compiling...$(WHITE)"
		@$(CC) $(MAIN) $(SRC) -o $(NAME) $(CFLAGS) $(CINC) $(LDFLAGS)
		@echo "$(PREFIX)$(BLUE)Compiled ! $(NAME)$(NC)"

clean :
		@echo "$(PREFIX)$(RED)Delete ! .~ and .# folder$(NC)"
		@rm -f *~ *#

fclean:		clean
		@echo "$(PREFIX)$(RED)Delete ! $(NAME)$(NC)"
		@rm -f $(NAME)

re:		fclean all clean

test_run:
		@echo "$(GREEN)[TESTS] $(BLUE)Start tests...$(NC)"
		gcc tests/tests.c -o $(NAME_TEST) -L. -lmy --coverage -lcriterion
		./unit_tests
		@gcovr --exclude tests/
		@echo "$(GREEN)[TESTS] $(BLUE)End tests...$(NC)"
		@rm *.g*


