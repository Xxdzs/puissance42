/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_puissance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:24:50 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 17:03:32 by jates-           ###   ########.fr       */
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
				NEW_ARRAY(enum e_player),
				7,
				6,
				HUMAN,
				false,
				BOT_NONE,
				DISPLAY_NONE
		});
}

void			game_state_init(t_game_state *game)
{
	fta_reserve((t_array*)game, game->width * game->height);
	game->start_player = (rand() * 2) % 2 + HUMAN;
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
	j = 0;
	while(i < game->height)
	{
		ft_printf("%d", (game->height - i) % 10);
		while(j < game->width)
		{
			j++;
			cell = ARRAY_GETL(uint8_t, &(game->board), game->width * i + j);
			if (cell == EMPTY)
				write(1, " ", 1);
			else if (cell == HUMAN)
				write(1, "*", 1);
			else if (cell == BOT)
				write(1, "O", 1);
		}
		ft_printf("%d", (game->height - i) % 10);
		i++;
		j = 0;
	}
	write(1, " ", 1);
	while (j++ < game->width)
		ft_printf("%d", j % 10);
}
