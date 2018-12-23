/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 05:43:29 by jates-            #+#    #+#             */
/*   Updated: 2018/12/23 05:43:32 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int is_aligned_east(t_game_state *game, int idx_x, int idx_y)
{
    int8_t  cell;
    int     nbr;

    nbr = 1;
    cell = ARRAY_GETL(int8_t, &(game->board), game->width * idx_x + idx_y);
    //if (idx_x + 1 < game->height)
        ;
    return (0);

}
