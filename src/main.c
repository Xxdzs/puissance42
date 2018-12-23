/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:58:54 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 07:58:39 by jates-           ###   ########.fr       */
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

	int ret;
	char *name;

	ret = 0;
	ft_printf("Hi! Let's play Connect Four together. ");
	ft_printf("First things first, what's your name ?\t(maximum 32 characters)\n");
	while(1)
	{
		ret = get_next_line(STDIN_FILENO, &name);
		if (ret == -1)
		{
			ft_printf(">>>>ERROR : get_next_line could not fetch the player name\n");
			break;
		}
		else if (ret == 1 && ft_strlen(name) > 32)
		{
			ft_printf("Sorry, I did not understand.\n");
			ft_printf("Could you tell me again your name ?\t(max 32 chars)\n");
		}
		else if (ret == 1)
		{
			game->player_name = name;
			break;
		}
		else
		{
			ft_printf(">>>>ERROR : player name does have anything to read\n");
			break;
		}
	}
}



/*
** booleen function which test if the column is empty or not i.e is it 
** possible to play or not.
*/

bool		is_move_possible(t_game_state *game, unsigned col)
{
	return (col < game->width && ARRAY_GETL(uint8_t, &game->board, col) == EMPTY);
}

/* 
** function which fetch the column selected by the player
** return : -1 if wrong or the index of the column
*/

int	get_player_move(t_game_state *game)
{
	int		move;
	int		ret;
	char	*str;

	str = NULL;
	move = 0;
	ret = 0;
	ft_printf("What are you going to play ?\n");
	while(1)
	{
		ret = get_next_line(STDIN_FILENO, &str);
		if (ret == -1)
		{
			ft_printf(">>>>ERROR : get_next_line could not fetch the column\n");
			break;
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
			ft_printf(">>>>ERROR : player column fetch does have anything to read\n");
			break;
		}
	}
	return (-1);
}

void ft_wait(unsigned time)
{
	unsigned idx;

	idx = 1;
	while (time--)
	{
		while(idx++)
			;
		idx = 1;
	}
}

/*
** function which insert the move with the sensation of gravity
** return the index of the ligne on which it was inserted
*/

unsigned put_jeton_gravity(t_game_state *game, unsigned col, uint8_t player)
{
	unsigned lig;

	lig = 0;
	if (game && player != EMPTY && is_move_possible(game, col)) //not necesserary just for debugging
	{
		//put player on lig col
		print_board1(game);
		while (lig + 1 < game->height && ARRAY_GETL(uint8_t, &game->board, game->width * lig + 1 + col) == EMPTY)
		{	
			ft_wait(42);
			//put empty on lig col
			lig++;
			//put player on lig col
			print_board1(game);
		}
		return (lig);
	}
	else 
		ft_printf(">>>>ERROR : jeton gravity has wrong input\n");
	return (lig);
}

/*
** function which insert the jeton on the board
** return the index of the ligne on which it was inserted
*/

unsigned put_jeton(t_game_state *game, unsigned col, uint8_t player)
{
	unsigned lig;

	lig = 0;
	if (game && player != EMPTY && is_move_possible(game, col)) //not necesserary just for debugging
	{
		while (lig + 1 < game->height && ARRAY_GETL(uint8_t, &game->board, game->width * lig + 1 + col) == EMPTY)
			lig++;
		//put player on lig col
		print_board1(game);
		return (lig);
	}
	else 
		ft_printf(">>>>ERROR : jeton insert has wrong input\n");
	return (lig);
}

/*
** Options without parameters
** -
** returns true if the name matches with an existing option,
** false otherwise
*/

static bool	set_option(t_game_state *game, const char *name, bool is_long)
{
	if (is_long && !ft_strcmp(name, "debug"))
		game->is_debug = true;
	else
		return (false);
	return (true);
}

/*
** Options with parameters
*/

static void	set_option_wp(t_game_state *game, const char *name,
						const char *value, bool is_long)
{
	if (*name == 'w' && !(is_long && ft_strcmp(name, "width")))
		game->width = ft_atoi(value);
	else if (*name == 'h' && !(is_long && ft_strcmp(name, "height")))
		game->height = ft_atoi(value);
	else if (*name == 'b' && !(is_long && ft_strcmp(name, "bot")))
		game->bot = bot_from_str(value);
	else if (*name == 'd' && !(is_long && ft_strcmp(name, "display")))
		game->display = display_from_str(value);
	else if (*name == 'j' && !(is_long && ft_strcmp(name, "jetons")))
		ft_strncpy(game->jetons, value, 3);
}

void		print_game(const t_game_state *game)
{
	const unsigned length = 12;

	ft_printf("\n%-*s : %s\n", length, "player_name", game->player_name);
	ft_printf("%-*s : %u\n", length, "width", game->width);
	ft_printf("%-*s : %u\n", length, "height", game->height);
	ft_printf("%-*s : %s\n", length, "start_player", str_from_player(game->start_player));
	ft_printf("%-*s : %c\n", length, "start jeton", game->jetons[game->start_player]);
	ft_printf("%-*s : %s\n", length, "bot", str_from_bot(game->bot));
	ft_printf("%-*s : %s\n\n", length, "display",
		str_from_display(game->display));
	ft_printf("%-*s : %s\n", length, "is_debug",
		game->is_debug ? "true" : "false");
	ft_printf("%s\n", fta_string((const t_array *)game, tmp_cell_to_string));
}

static void	parse_arguments(t_game_state *game, int ac, char **av)
{
	bool			is_long;
	const char		*name;
	const char		*value;

	while (--ac && *++av)
	{
		if (!(is_long = false) && **av != '-')
			continue ;
		if (*++*av == '-' && (is_long = true) && *++*av == '\0')
			break ;
		if ((name = *av) && set_option(game, name, is_long))
			continue ;
		if (is_long)
			if ((value = ft_strchr(*av, '=')) == NULL && ac--)
				value = *++av;
			else
				*(char*)value++ = '\0';
		else
			value = (*++*av == '\0' && ac-- ? *++av : *av);
		if (value == NULL)
			value = "";
		set_option_wp(game, name, value, is_long);
	}
}

int			main(int ac, char **av)
{
	t_game_state	game[1];

	srand(time(NULL));
	*game = new_game_state();
	parse_arguments(game, ac, av);
	game_state_init(game);
	print_game(game);
	game->bot = BOT_RANDOM;
	print_board1(game);
	print_board2(game);
//	run_game(game);
	game_state_clear(game);
	return (0);
}
