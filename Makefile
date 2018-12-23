#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2018/12/22 17:10:41 by jates-           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=puissance4

FILES= board_puissance \
		case_state \
		display \
		enum \
		julia \
		main \
		none \
		play \
		run  

LIB_FILES= libft.a
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
LIBPATH:=libft/
HDRPATH:=include/
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
LIB:=$(addprefix $(LIBPATH),$(LIB_FILES))
# ==================

MAKEFLAGS+=-sj

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo $(EOC)
	@echo $(CYAN) " - Compiling $@" $(EOC)
	$(CC)  $^ -o $@
	@echo $(GREEN) " - Done" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHPATH)
	@echo -n .
	$(CC) $(CFLAGS) -c $< -o $@

$(CCHPATH):
	mkdir -p $@

$(LIBPATH)%.a:
	make -sC $(@D)

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
