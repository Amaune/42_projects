# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 15:16:30 by amaune       #+#   ##    ##    #+#        #
#    Updated: 2018/11/13 16:30:05 by amaune      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PATH_OBJ = ./objs/

#******************************************************************************#
#								COLORS										   #
#******************************************************************************#

RED = \e[31m
GREEN = \e[92m
GREEN1 = \e[92;7m
END = \e[97m
END1 = \e[0m

#******************************************************************************#
#								Objects										   #
#******************************************************************************#

FILES_Fillit = fillit
OBJ_Fillit = $(addprefix $(PATH_OBJ_Fillit), $(addsuffix .o , $(FILES_Fillit)))
SRC_Fillit = $(addprefix $(PATH_SRC_Fillit), $(addsuffix .c , $(FILES_Fillit)))

all: $(NAME)

$(NAME): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN1) $(END1)"

clean: 
	@rm -rf $(OBJ)
	@echo "$(RED)[Object Deleted] $(END)\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)[$(NAME) Deleted] $(END)"

re: fclean all
