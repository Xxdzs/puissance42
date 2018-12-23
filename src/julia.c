/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:58:54 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 12:27:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "libft.h"
#include "ft_printf.h"
#include "ft_array.h"
#include "get_next_line.h"

#include <stdbool.h>
#include <time.h>

/*
** Fonction gets the answer of the player
*/

void		get_player_name(t_game_state *game)
{
	int		ret;
	char	*name;

	ret = 0;
	ft_printf("Hi! Let's play Connect Four together. First things first, ");
	ft_printf("what's your name ?\n");
	while (1)
	{
		ret = get_next_line(STDIN_FILENO, &name);
		if (ret == -1)
		{
			ft_printf(">>ERROR : gnl could not fetch the player name\n");
			break ;
		}
		else if (ret == 1 && ft_strlen(name) > 32)
		{
			ft_printf("Sorry, I did not understand.\n");
			ft_printf("Could you tell me again your name ?\t(max 32 chars)\n");
		}
		else if (ret == 1)
		{
			game->player_name = name;
			break ;
		}
		else
		{
			ft_printf(">>ERROR : player name does have anything to read\n");
			break ;
		}
	}
}

/*
** function which fetch the column selected by the player
** return : -1 if wrong or the index of the column
*/

int			get_player_move(t_game_state *game)
{
	int		move;
	int		ret;
	char	*str;

	str = NULL;
	move = 0;
	ret = 0;
	ft_printf("What are you going to play ?\n");
	while (1)
	{
		ret = get_next_line(STDIN_FILENO, &str);
		if (ret == -1)
		{
			ft_printf(">>ERROR : get_next_line could not fetch the column\n");
			break ;
		}
		else if (ret == 1
			&& (((move = ft_atoi(str)) < 1) || !is_move_possible(game, --move)))
		{
			ft_printf("Sorry, I did not understand.\n");
			ft_printf("Could you tell me your choice ?\n");
		}
		else if (ret == 1)
			return (move);
		else
		{
			ft_printf(">>ERROR : player column fetch does have anything to read\n");
			break ;
		}
	}
	return (-1);
}

/*
** custom made function to wait
*/

void		ft_wait(unsigned time)
{
	unsigned idx;

	idx = 1;
	while (time--)
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

unsigned	put_jeton_gravity(t_game_state *game, unsigned col, uint8_t player)
{
	unsigned lig;

	lig = 0;
	if (game && player != EMPTY && is_move_possible(game, col)) /* not necesserary just for debugging */
	{
		ARRAY_GETL(uint8_t, &game->board, game->width * lig + col) = player;
		print_board(game);
		while (lig + 1 < game->height && ARRAY_GETL(uint8_t, &game->board, game->width * lig + 1 + col) == EMPTY)
		{
			ft_wait(42);
			ARRAY_GETL(uint8_t, &game->board, game->width * lig + col) = EMPTY;
			lig++;
			ARRAY_GETL(uint8_t, &game->board, game->width * lig + col) = player;
			print_board(game);
		}
		return (lig);
	}
	else
		ft_printf(">>ERROR : jeton gravity has wrong input\n");
	return (lig);
}

/*
** function which insert the jeton on the board
** return the index of the ligne on which it was inserted
*/

unsigned	put_jeton(t_game_state *game, unsigned col, uint8_t player)
{
	unsigned lig;

	lig = 0;
	if (game && player != EMPTY && is_move_possible(game, col)) /* not necesserary just for debugging */
	{
		while (lig + 1 < game->height && ARRAY_GETL(uint8_t, &game->board, game->width * lig + 1 + col) == EMPTY)
			lig++;
		ARRAY_GETL(uint8_t, &game->board, game->width * lig + col) = player;
		print_board(game);
		return (lig);
	}
	else
		ft_printf(">>ERROR : jeton insert has wrong input\n");
	return (lig);
}
