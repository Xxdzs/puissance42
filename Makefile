#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2018/12/22 13:17:17 by jates-           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=libft.a

FILES=ft_atoi ft_bzero ft_itoa ft_itoa_base ft_memalloc ft_memccpy ft_memchr \
	ft_memdel ft_memcmp ft_memcpy ft_memmove ft_memset ft_memdup ft_putchar \
	ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr \
	ft_putstr_fd ft_realloc ft_print_memory ft_gnl ft_malloc ft_memswp \
	ft_string is_refresh

LIBFT_PATH:=libft/

LIB_FILES= libtf.a
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
LIBPATH:=libft/
HDRPATH:=include/
CFLAGS:=-Wall -Wextra -I $(HDRPATH) -ansi
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
LIB:=$(addprefix $(LIBPATH), $(LIB_FILES))
# ==================

MAKEFLAGS+=-sj

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo $(EOC)
	@echo $(CYAN) " - Compiling $@" $(EOC)
	ar rcs $@ $^
	@echo $(GREEN) " - Done" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHPATH)
	@echo -n .
	$(CC) $(CFLAGS) -c $< -o $@

$(CCHPATH):
	mkdir -p $(addprefix $@/,$(FOLDERS))

$(LIBPATH)%.a :
	make -C $@(D)

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
