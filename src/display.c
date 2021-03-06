/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:07:04 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/28 16:10:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include "puissance.h"
#include "ft_printf.h"

#include <stdlib.h>
#include <unistd.h>

/*
** Function which prints the board simply
*/

static void			print_number_simple(const t_game_state *game)
{
	unsigned j;

	j = 0;
	write(1, " ", 1);
	while (j++ < game->width)
		ft_printf("%1d", j % 10);
	write(1, "\n", 1);
}

static void			print_board_simple(const t_game_state *game)
{
	unsigned	i;
	unsigned	j;
	uint8_t		cell;

	i = 0;
	print_number_simple(game);
	while (i < game->height)
	{
		ft_printf("%d", (game->height - i) % 10 + (j = 0));
		while (j < game->width)
		{
			cell = ARRAY_GETL(uint8_t, &(game->board), game->width * i + j);
			if (cell <= BOT)
				write(1, game->jetons + cell, 1);
			else
				write(1, ".", 1);
			j++;
		}
		ft_printf("%d\n", (game->height - i) % 10);
		i++;
	}
	print_number_simple(game);
}

/*
** Function which prints the values of each cell
*/

static void			print_number_beautiful(const t_game_state *game)
{
	unsigned	j;

	j = 0;
	write(1, "|   ", 4);
	while (j++ < game->width)
		ft_printf("|% 3d", j % 1000);
	write(1, "|\n", 2);
	draw_ligne(game->width * 4 + 1, '_');
}

static void			print_board_numbers(const t_game_state *game)
{
	unsigned	i;
	unsigned	j;
	uint8_t		cell;

	i = 0;
	draw_ligne(game->width * 4 + 1, '_');
	print_number_beautiful(game);
	while (i < game->height)
	{
		ft_printf("|% 3d", (game->height - i) % 1000 + (j = 0));
		while (j++ < game->width)
		{
			cell = ARRAY_GETL(uint8_t, \
			(const t_array*)game, game->width * i + j);
			ft_printf("| %hhu ", cell, 1);
		}
		ft_printf("|% 3d|\n", (game->height - i++) % 1000);
		draw_ligne(game->width * 4 + 1, '_');
	}
	print_number_beautiful(game);
}

void				print_board(const t_game_state *game)
{
	void (*const functions[])() = {
		&do_nothing_at_all,
		&print_board_simple,
		&print_board_numbers
	};

	functions[game->display](game);
}
