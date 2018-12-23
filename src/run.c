/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/22 23:54:18 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

#include <stdbool.h>

bool	play_round(t_game_state *game, uint8_t player)
{
	print_board(game);
	ft_printf("%s\n", player)
}

unsigned play_random(t_game_state *game)
{
	unsigned move;

	move = rand() % game->width;
	while(!is_move_possible(game, move))
		move = rand() % game->width;
	return (move);
}

void	run_game(t_game_state *game)
{
	unsigned	turn;

	turn = 0;
	while (play_round(game,
			HUMAN + ((turn + (game->start_player == BOT)) % 2)))
		turn++;
	print_board(game);
}
