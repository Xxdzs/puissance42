/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_puissance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:24:50 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 15:06:56 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance.h"
#include <stdlib.h>

void	new_game_state(t_game_state *game)
{
	game->board = *fta_alloc(game->width * game->height);
	game->start_player = (rand() * 2) % 2 + HUMAN;

}

