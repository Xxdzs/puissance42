/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_puissance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:24:50 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 16:03:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include "puissance.h"

#include <stdlib.h>

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
