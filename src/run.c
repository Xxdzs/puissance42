/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/28 17:05:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "ft_printf.h"

#include <stdbool.h>
#include <stdlib.h>

bool		play_round(t_game_state *game, uint8_t player)
{
	unsigned			column;
	const char *const	player_str = str_from_player(player);

	print_board(game);
	ft_printf("It is the %s's turn\n", player_str);
	column = (player == HUMAN ? play_prompt(game) : play_bot(game));
	if (!(game->is_animated ? put_jeton_gravity(game, column, player)
					: put_jeton(game, column, player)))
	{
		ft_printf("The %s played a wrong move, and lost\n", player_str);
		game->winner = (player == BOT ? HUMAN : BOT);
		return (false);
	}
	if (iswin_case(game, column_top(game, column) + 1, column, player))
	{
		game->winner = player;
		return (false);
	}
	return (true);
}

void		run_game(t_game_state *game)
{
	unsigned	turn;

	turn = 0;
	while (turn < 42 && play_round(game,
			HUMAN + ((turn + (game->start_player == BOT)) % 2)))
		turn++;
	print_board(game);
	if (game->winner == EMPTY)
		ft_printf("Draw");
	else
		ft_printf("And the winner is : The %s\n",\
				str_from_player(game->winner));
}
