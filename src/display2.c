/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:07:04 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 22:55:37 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include "puissance.h"
#include "ft_printf.h"

#include <stdlib.h>
#include <unistd.h>

/*
** Function which prints a ligne
*/

void			draw_ligne(size_t size, char c)
{
	char str[2048];

	if (size < 2047)
		ft_memset(str, c, size);
	else
	{
		ft_memset(str, c, 2048);
		while (size > 2047 && (size -= 2048))
			write(1, &c, 2048);
	}
	str[size] = '\n';
	write(1, str, size + 1);
}

/*
** custom made function to sleep
*/

void			ft_sleep(unsigned tempo)
{
	unsigned short idx;

	idx = 1;
	while (tempo--)
	{
		while (idx++)
			;
		idx = 1;
	}
}

/*
** function which insert the move with the sensation of gravity
** return the index of the ligne on which it was inserted
*/

unsigned		put_jeton_gravity(t_game_state *game,\
				unsigned col, uint8_t player)
{
	unsigned lig;

	lig = 0;
	if (game && player != EMPTY && is_move_possible(game, col)) /* not necesserary just for debugging */
	{
		ARRAY_GETL(uint8_t, &game->board, game->width * lig + col) = player;
		print_board(game);
		while (lig + 1 < game->height \
		&& ARRAY_GETL(uint8_t, &game->board, game->width * lig + 1 + col) == EMPTY)
		{

			ARRAY_GETL(uint8_t, &game->board, game->width * lig + col) = EMPTY;
			lig++;
			ARRAY_GETL(uint8_t, &game->board, game->width * lig + col) = player;
			ft_sleep(1848);
			ft_printf("\033[%dA", \
			(game->display == 1) ? game->height + 2 : game->height * 4 + 1);
			print_board(game);
		}
		return (lig);
	}
	else
		ft_printf(">>ERROR : jeton gravity has wrong input\n");
	return (lig);
}
