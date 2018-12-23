/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:56:21 by sid               #+#    #+#             */
/*   Updated: 2018/12/23 22:49:13 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "ft_array.h"

unsigned			column_top(const t_game_state *game, unsigned column)
{
	unsigned	lign;

	lign = game->height;
	while (lign-- > 0)
		if (ARRAY_GETL(uint8_t, (const t_array*)game,
					game->width * lign + column) == EMPTY)
			return (lign);
	return (game->height);
}

t_array				create_layer(const t_game_state *game)
{
	t_array		layer;
	unsigned	col;

	layer = NEW_ARRAY(unsigned);
	fta_reserve(&layer, game->width);
	layer.size = game->width;
	col = game->width;
	while (col-- > 0)
		ARRAY_GETL(unsigned, &layer, col) = column_top(game, col);
	return (layer);
}
