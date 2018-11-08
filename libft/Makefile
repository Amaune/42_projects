# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 18:18:28 by amaune       #+#   ##    ##    #+#        #
#    Updated: 2018/10/18 16:52:12 by amaune      ###    #+. /#+    ###.fr      #
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
CFLAGS = -Wall -Werror -Wextra -Includes
OBJ = ft_putchar.o  ft_putstr.o \
	  ft_strcmp.o ft_strlen.o ft_lstdelone.o \
	  ft_atoi.o ft_memset.o ft_strsplit.o ft_swap.o\
	  ft_putnbr.o ft_strcat.o ft_putendl.o ft_sqrt.o\
	  ft_strcpy.o ft_memmove.o ft_putchar_fd.o ft_strrev.o \
	  ft_strdup.o ft_strlcat.o ft_putstr_fd.o ft_range.o \
	  ft_strncat.o ft_strncmp.o ft_putendl_fd.o ft_lstmap.o\
	  ft_strncpy.o ft_strnstr.o ft_putnbr_fd.o ft_lstiter.o\
	  ft_strstr.o ft_bzero.o ft_itoa.o ft_lenint.o ft_lstadd.o \
	  ft_memcpy.o	ft_memccpy.o ft_lstnew.o ft_lstdel.o ft_realloc.o\
	  ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	  ft_toupper.o ft_tolower.o ft_memchr.o ft_memcmp.o ft_strchr.o \
	  ft_strrchr.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o \
	  ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o \
	  ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o \


all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) $?
	@printf "\n$(GREEN)[Succes]$(END)\n"

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN1) $(END1)" 

clean:
	@rm -f $(OBJ)
	@printf "$(RED)[Object Deleted] $(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)[Libft.a Deleted]$(END)\n"

re: fclean all
