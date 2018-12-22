/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_puissance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:24:50 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 22:11:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include "puissance.h"
#include "ft_printf.h"

#include <stdlib.h>
#include <unistd.h>

/*
** Fonction which initialize the main structure of puissance 4
*/

t_game_state	new_game_state(void)
{
	return ((t_game_state){
				.board = NEW_ARRAY(enum e_player),
				.player_name = "Player",
				.width = 7,
				.height = 6,
				.jetons = " XO"
				.start_player = HUMAN,
				.bot = BOT_GREEDY,
				.display = DISPLAY_SIMPLE,
				.is_debug = false,
		});
}

void			game_state_init(t_game_state *game)
{
	size_t	size = game->width * game->height;

	fta_reserve((t_array*)game, size);
	game->board.size = size;
	ft_memset(game->board.data, EMPTY, size);
	game->start_player = (rand() * 2) % 2 + HUMAN;
}

void			game_state_clear(t_game_state *game)
{
	fta_clear((t_array*)game);
	game->width = 0;
	game->height = 0;
}

/*
** Fonction which prints the board
*/

void			print_board(t_game_state *game)
{
	unsigned	i;
	unsigned	j;
	uint8_t		cell;

	i = 0;
	j = 0;
	write(1, " ", 1);
	while (j++ < game->width)
		ft_printf("%d", j % 10);
	write(1, "\n", 1);
	while (i < game->height)
	{
		j = 0;
		ft_printf("%d", (game->height - i) % 10);
		while (j < game->width)
		{
			j++;
			cell = ARRAY_GETL(uint8_t, &(game->board), game->width * i + j);
			write(1, game->jetons + cell, 1);
		}
		ft_printf("%d\n", (game->height - i) % 10);
		i++;
	}
	write(1, " ", 1);
	j = 0;
	while (j++ < game->width)
		ft_printf("%d", j % 10);
	write(1, "\n", 1);
}
