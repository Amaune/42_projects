# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 18:18:28 by amaune       #+#   ##    ##    #+#        #
#    Updated: 2018/11/13 16:54:58 by amaune      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

RED = \e[31m
RED1 = \e[31;7m
GREEN = \e[92m
GREEN1 = \e[92;7m
END = \e[97m
END1 = \e[0m

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PATH_SRC = ./src/
PATH_OBJ = ./obj/
PATH_INC = ./include/
FILES = ft_putchar  	ft_putstr	\
		ft_strcmp 		ft_strlen	\
	  	ft_lstdelone 	ft_atoi		\
	  	ft_memset 		ft_strsplit \
	  	ft_putnbr 		ft_strcat	\
	  	ft_putendl 		ft_sqrt		\
	  	ft_strcpy 		ft_memmove	\
		ft_putchar_fd 	ft_strrev	\
		ft_strdup 		ft_strlcat	\
		ft_putstr_fd 	ft_range	\
		ft_strncat 		ft_strncmp	\
		ft_putendl_fd 	ft_lstmap	\
		ft_strncpy 		ft_strnstr	\
		ft_putnbr_fd 	ft_lstiter	\
		ft_strstr 		ft_bzero	\
		ft_itoa 		ft_lenint	\
		ft_lstadd 		ft_realloc	\
		ft_memcpy		ft_memccpy	\
		ft_lstnew 		ft_lstdel	\
		ft_isalpha 		ft_isdigit	\
		ft_isalnum 		ft_isascii	\
		ft_isprint 		ft_strtrim	\
		ft_toupper 		ft_tolower	\
		ft_memchr 		ft_memcmp	\
		ft_strchr 		ft_strmapi	\
		ft_strrchr 		ft_memalloc \
		ft_memdel 		ft_strnew	\
		ft_strdel 		ft_swap		\
		ft_strclr 		ft_striter	\
		ft_striteri 	ft_strmap	\
		ft_strequ 		ft_strnequ	\
		ft_strsub 		ft_strjoin	\
		ft_lstcount		get_next_line \
	  
SRC_FILES = $(addprefix $(PATH_SRC), $(addsuffix .c , $(FILES)))
OBJ_FILES = $(addprefix $(PATH_OBJ), $(addsuffix .o , $(FILES)))



all: obj $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES) $?
	@printf "\n$(GREEN)[Succes]$(END)\n"

obj:
	@mkdir -p obj

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(PATH_INC)*.h
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $< -o $@
	@printf "$(GREEN1) $(END1)" 

clean:
	@rm -rf $(PATH_OBJ)
	@printf "$(RED)[Object libft Deleted] $(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)[Libft.a Deleted]$(END)\n"

re: fclean all
