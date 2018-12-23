/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 13:05:42 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "ft_printf.h"

#include <stdbool.h>
#include <stdlib.h>

bool		play_round(t_game_state *game, uint8_t player)
{
	print_board1(game);
	ft_printf("%s\n", str_from_player(player));
	return (false);
}

unsigned	play_random(t_game_state *game)
{
	unsigned move;

	move = rand() % game->width;
	while (!is_move_possible(game, move))
		move = rand() % game->width;
	return (move);
}

void		run_game(t_game_state *game)
{
	unsigned	turn;

	turn = 0;
	while (play_round(game,
			HUMAN + ((turn + (game->start_player == BOT)) % 2)))
		turn++;
	print_board1(game);
}
