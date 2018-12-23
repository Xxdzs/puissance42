/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 05:43:29 by jates-            #+#    #+#             */
/*   Updated: 2018/12/23 13:20:00 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

/*
** booleen function which test if the column is empty or not i.e is it
** possible to play or not.
*/

bool		is_move_possible(const t_game_state *game, unsigned col)
{
	return (col < game->width
			&& ARRAY_GETL(uint8_t, &game->board, col) == EMPTY);
}

/*
** booleen function of the is_same_bool
** return if (the cell == player)
*/

bool		is_same_bool(t_game_state *game, int lig, int col, int8_t player)
{
	int8_t	cell;

	if (lig < 0 || col < 0 || (unsigned)lig >= game->height
			|| (unsigned)col >= game->width)
		return (0);
	else if (!(cell = ARRAY_GETL(int8_t,\
					&(game->board), game->width * lig + col)))
		return (0);
	else if (cell == player)
		return (1);
	else
		return (0);
}

int			is_same_case(t_game_state *game, int lig, int col, int8_t player)
{
	int8_t	cell;

	if (lig < 0 || col < 0 || (unsigned)lig >= game->height
			|| (unsigned)col >= game->width)
		return (-2);
	else if (!(cell = ARRAY_GETL(int8_t,\
					&(game->board), game->width * lig + col)))
		return (0);
	else if (cell == player)
		return (1);
	else
		return (-1);
}

/*
** booleen function which test if the column if the move is winner
*/

bool		iswin_case(const t_game_state *game, int lig, int col, int8_t player)
{
	int			a;
	int			i;
	int			j;
	unsigned	n;

	a = 9;
	while (a-- > 0)
	{
		i = (a % 3) - 1;
		j = (a / 3) - 1;
		if (i == 0 && j != 1)
			continue ;
		n = 0;
		while (++n < 4)
			if (ARRAY_GETL(uint8_t, &(game->board), game->width * (lig + j * n) + col + i * n) != player)
				break ;
		if (n == 4)
			return (true);
	}
	return (false);
}
