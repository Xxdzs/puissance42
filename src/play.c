/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:49:12 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 22:11:03 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "ft_array.h"
#include "ft_printf.h"

#include <stdlib.h>

unsigned			play_random(t_game_state *game)
{
	unsigned move;

	move = rand() % game->width;
	while (!is_move_possible(game, move))
		move = rand() % game->width;
	return (move);
}

unsigned			play_prompt(t_game_state *game)
{
	const int ret = get_player_move(game);

	return (ret < 0 ? game->width : (unsigned)ret);
}

unsigned			winning_column(const t_game_state *game,
							const t_array *layer,
							uint8_t player)
{
	unsigned	col;

	col = game->width;
	while (col-- > 0)
		if (iswin_case(game, ARRAY_GETL(unsigned, layer, col), col, player))
			return (col);
	return (game->width);
}

unsigned			play_greedy(t_game_state *game)
{
	const t_array	layer = create_layer(game);
	unsigned		col;

	if ((col = winning_column(game, &layer, BOT)) < game->width)
		return (col);
	if ((col = winning_column(game, &layer, HUMAN)) < game->width)
		return (col);
	fta_clear((t_array *)&layer);
	return (0);
}

unsigned			play_bot(t_game_state *game)
{
	unsigned (*const functions[])() = {
		(void*)&do_nothing_at_all,
		&play_prompt,
		&play_random,
		&play_greedy,
		&play_greedy
	};

	return (functions[game->bot](game));
}
