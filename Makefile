#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2018/12/22 16:20:45 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=puissance4

FILES= board_puissance main enum

LIBS= ft
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
LIBPATH:=libft/
HDRPATH:=include/
LFLAGS=$(addprefix -L,$(LIBPATH))
LFLAGS+=$(addprefix -l,$(LIBS))
CFLAGS:=-Wall -Wextra -ansi -I $(HDRPATH) -I $(LIBPATH)$(HDRPATH)
# ==================

# ===== Colors =====
EOC:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ====== Auto ======
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
LIB:=$(addprefix $(LIBPATH)lib,$(addsuffix .a,$(LIBS)))
# ==================

#MAKEFLAGS+=-sj

all: $(NAME)

$(NAME): $(OBJ) | $(LIB)
	@echo $(EOC)
	@echo $(CYAN) " - Compiling $@" $(EOC)
	$(CC) $(LFLAGS) $^ -o $@
	@echo $(GREEN) " - Done" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHPATH)
	@echo -n .
	$(CC) $(CFLAGS) -c $< -o $@

$(CCHPATH):
	mkdir -p $@

%.a:
	make -sC $(@D)
	echo "Lib"

clean:
	rm -rf $(CCHPATH)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

norm:
	@echo $(RED)
	norminette $(SRC) $(HDRPATH) | grep -v Norme -B1 || true
	@echo $(EOC)

.PHONY: all clean fclean re norm
