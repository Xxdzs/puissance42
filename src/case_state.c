/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 05:43:29 by jates-            #+#    #+#             */
/*   Updated: 2018/12/23 13:14:30 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

/*
** booleen function which test if the column is empty or not i.e is it
** possible to play or not.
*/

bool		is_move_possible(t_game_state *game, unsigned col)
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

bool		iswin_case(t_game_state *game, int lig, int col, int8_t player)
{
	int i;
	int n;

	n = -1;
	i = -4;
	while (++i < 4 && (is_same_bool(game, lig, col - i, player) || (n = -1)))
		++n;
	if (n >= 4 && (i = -4))
		return (true);
	n = -1;
	i = -4;
	while (++i < 4 && (is_same_bool(game, lig - i,\
					col - i, player) || (n = -1)))
		++n;
	if (n >= 4 && (i = -4))
		return (true);
	n = -1 ;
	while (++i < 4 && (is_same_bool(game, lig + i,\
					col - i, player) || (n = -1)))
		++n;
	if (n >= 4 && (i = -4))
		return (true);
	n = -1;
	while (++i < 0 && (is_same_bool(game, lig + i, col, player) || (n = -1)))
		++n;
	return (n >= 4);
}
