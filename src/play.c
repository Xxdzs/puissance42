/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:49:12 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 19:55:43 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"

#include <stdbool.h>
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

unsigned			play_bot(t_game_state *game)
{
	unsigned (*const functions[])() = {
		(void*)&do_nothing_at_all,
		&play_prompt,
		&play_random,
		&play_random,
		&play_random
	};

	return (functions[game->bot](game));
}
