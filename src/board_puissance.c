/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_puissance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:24:50 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 22:28:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include "puissance.h"
#include "ft_printf.h"

#include <stdlib.h>
#include <unistd.h>

/*
** Fonction which initialize the main structure of puissance 4
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

	fta_reserve((t_array*)game, size);
	game->board.size = size;
	ft_memset(game->board.data, EMPTY, size);
	game->start_player = (rand() % 2) ? HUMAN : BOT;
}

void			game_state_clear(t_game_state *game)
{
	fta_clear((t_array*)game);
	game->width = 0;
	game->height = 0;
}

/*
** Function which prints the board simplely
*/

void			print_board1(const t_game_state *game)
{
	unsigned	i;
	unsigned	j;
	uint8_t		cell;

	i = 0;
	write(1, " ", 1 + (j = 0));
	while (j++ < game->width)
		ft_printf("%1d", j % 10);
	write(1, "\n", 1);
	while (i < game->height)
	{
		ft_printf("%d", (game->height - i) % 10 + (j = 0));
		while (j < game->width)
		{
			cell = ARRAY_GETL(uint8_t, &(game->board), game->width * i + j);
			write(1, game->jetons + cell, 1);
			j++;
		}
		ft_printf("%d\n", (game->height - i++) % 10);
	}
	write(1, " ", 1 + (j = 0));
	while (j++ < game->width)
		ft_printf("%1d", j % 10);
	write(1, "\n", 1);
}

/*
** Function which prints the board more beautifully
*/
static void		draw_ligne(size_t size, char c)
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

void			print_board2(const t_game_state *game)
{
	unsigned	i;
	unsigned	j;
	uint8_t		cell;

	i = 0;

	draw_ligne(game->width * 4 + 1, '_');
	write(1, "|   ", 4 + (j = 0));
	while (j++ < game->width)
		ft_printf("|% 3d", j % 1000);
	write(1, "|\n", 2);
	draw_ligne(game->width * 4 + 1, '_');
	while (i < game->height)
	{
		ft_printf("|% 3d", (game->height - i) % 1000 + (j = 0));
		while (j++ < game->width)
		{
			cell = ARRAY_GETL(uint8_t, (const t_array*)game, game->width * i + j);
			ft_printf("| %hhu ", cell, 1);
		}
		ft_printf("|% 3d|\n", (game->height - i++) % 1000);
		draw_ligne(game->width * 4 + 1, '_');
	}
	write(1, "|   |", 4 + (j = 0));
	while (j++ < game->width)
		ft_printf("|% 3d", j % 1000);
	write(1, "\n", 1);
	draw_ligne(game->width * 4 + 1, '_');
}
