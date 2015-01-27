# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 12:42:16 by mbourdel          #+#    #+#              #
#    Updated: 2015/01/27 15:33:26 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c ft_pwd_env.c ft_seek_option.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

LIBFT_PATH = ./libft/

all: $(NAME)

$(NAME):
	@echo "-----Libft Makefile-----"
	@cd $(LIBFT_PATH); $(MAKE) -f Makefile
	@echo "-----Libft Makefile-----"
	@gcc $(FLAG) $(SRC) -o $(NAME) $(LIBFT_PATH)libft.a
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|      ft_ls      |"
	@echo "|   was summoned  |"
	@echo "[=================]"

clean:
	@echo "-----ft_ls Makefile-----"
	@rm -rf $(OBJ)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     XXXXX.o     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"


fclean: clean
	@echo "-----ft_ls Makefile-----"
	@rm -rf $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|      ft_ls      |"
	@echo "|  was destroyed  |"
	@echo "[=================]"


re: fclean all

deslib:
	@echo "-----Libft Makefile-----"
	@cd $(LIBFT_PATH); $(MAKE) fclean -f Makefile

total: deslib re
