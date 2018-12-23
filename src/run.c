/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 14:14:33 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "ft_printf.h"

#include <stdbool.h>
#include <stdlib.h>

bool	play_round(t_game_state *game, uint8_t player)
{
	unsigned	column;

	print_board(game);
	ft_printf("It is the %s's turn\n", str_from_player(player));
	column = (player == HUMAN ? play_prompt(game) : play_bot(game));
	return (true);
}

void	run_game(t_game_state *game)
{
	unsigned	turn;

	turn = 0;
	while (turn < 5 && play_round(game,
			HUMAN + ((turn + (game->start_player == BOT)) % 2)))
		turn++;
	print_board(game);
}
