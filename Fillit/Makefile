# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 15:16:30 by amaune       #+#   ##    ##    #+#        #
#    Updated: 2018/11/22 11:57:15 by amaune      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

LIBS = libft/libft.a

SRC = src/fill_checkpose.c src/fill_error.c src/fill_map.c src/fill_solve.c \
		src/fill_read_it.c src/lstcount.c src/main.c src/fill_free.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Werror -Wextra -Wall -Iincludes -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft	
	@$(CC) $(LIBS) $(OBJ) -o $@

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<
clean:
	@rm -f $(OBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all