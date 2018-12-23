/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:49:12 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 14:15:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "ft_printf.h"

#include <stdbool.h>
#include <stdlib.h>

static unsigned		play_random(t_game_state *game)
{
	unsigned move;

	move = rand() % game->width;
	while (!is_move_possible(game, move))
		move = rand() % game->width;
	return (move);
}

unsigned			play_prompt(t_game_state *game)
{
	char	*line;
	int		ans;

	if (get_nex_line(0, &line) < 0)
		return (0);
	ans = ft_atoi(line) - 1;
	return (0 <= ans && ans < game->width ? ans : 0);
}

bool				play_bot(t_game_state *game)
{
	unsigned (*const functions[])() = {
		do_nothing_at_all
		&play_prompt,
		&play_random,
		&play_random,
		&play_random
	};

	function[game->bot](game);
}
