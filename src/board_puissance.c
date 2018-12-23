/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_puissance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:24:50 by jates-            #+#    #+#             */
/*   Updated: 2018/12/23 13:54:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include "puissance.h"
#include "ft_printf.h"

#include <stdlib.h>
#include <unistd.h>

/*
** Constructor, init and destructor for the game_state struct
*/

t_game_state	new_game_state(void)
{
	return ((t_game_state){
				.board = NEW_ARRAY(uint8_t),
				.player_name = "Player",
				.width = 7,
				.height = 6,
				.jetons = " XO",
				.start_player = HUMAN,
				.bot = BOT_GREEDY,
				.display = DISPLAY_SIMPLE,
				.is_debug = false
		});
}

void			game_state_init(t_game_state *game)
{
	const size_t	size = game->width * game->height;

	if (fta_reserve((t_array*)game, size) != 0)
		return ;
	game->board.size = size;
	ft_memset(game->board.data, 0, size * game->board.type_size);
	game->start_player = (rand() % 2) ? HUMAN : BOT;
}

void			game_state_clear(t_game_state *game)
{
	fta_clear((t_array*)game);
	game->width = 0;
	game->height = 0;
}
