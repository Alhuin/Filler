# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/14 19:15:23 by jmonneri     #+#   ##    ##    #+#        #
#    Updated: 2018/04/11 21:07:58 by jjanin-r    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = jjanin-r.filler
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_LIBFT = ./libft/
PATH_SRC = ./srcs/
PATH_INC = ./incs/
SRC = $(addprefixx $(PATH_SRC), $(FILES))
SRCO = $(SRC:.c=.o)
INC = $(addprefix $(PATH_INC), filler.h )
FILES = read.c

#******************************************************************************#
#                                    RULES                                     #
#******************************************************************************#

all: $(NAME)

clean:
	@printf "\n\033[1m🦄 🦄 🦄 🦄 SUPPRESSION DES OBJETS🦄 🦄 🦄 🦄\033[0m\n"
	@make clean -C ./libft/
	@rm -rf $(SRCO)

fclean: clean
	@printf "\n\033[1m🦄 🦄 🦄 🦄 SUPPRESSION DE $(NAME)🦄 🦄 🦄 🦄\033[0m\n"
	@rm -rf $(NAME)
	@rm -rf ./libft/libft.a

re: fclean all

#******************************************************************************#
#                               Comp FILLER                                    #
#******************************************************************************#


$(NAME):
	@printf "\n\033[1m🦄 🦄 🦄 🦄 CREATION DE jjanin-r.filler🦄 🦄 🦄 🦄\033[0m\n"
	@make -C ./libft/
	@$(CC) $(CC_FLAGS) $(SRC) $(PATH_LIBFT)libft.a -o $(NAME)
	@printf "  👍  👍  👍 \033[1mEXECUTABLE CREE\033[0m👍  👍  👍\n\n"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INC)
	@printf "0️⃣  Compilation de \033[1m$<\033[0m en \033[1m$@\033[0m"
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC)
	@printf "   \033[0;32m[OK]\033[0m\n"
