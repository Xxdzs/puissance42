/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:58:54 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 00:17:11 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "libft.h"
#include "ft_printf.h"
#include "ft_array.h"

#include <stdbool.h>

/*
** Fonction gets the answer of the player
*/

void		get_player_name(t_game_state *game)
{

	int ret;
	char *name;

	ret = 0;
	printf("Hi! Let's play Connect Four together. ")i;
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
			ft_printf("Sorry, I did not understand.\n")
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

bool		is_move_possible(t_game_state *game, unsigned col)
{
			if (col > width)
				return (0);
			else if (!(game->board-> )) //check that the cell col last ligne is empty
				return (1);
			else
				return (0);							
}

void		get_player_move()
{
	uint8_t	move;

	move = 0;
	printf("What are you going to play ?\n")
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
		ft_memcpy(game->jetons, value, 3);
}

void		print_game(t_game_state *game)
{
	const unsigned length = 12;

	ft_printf("\n%-*s : %u\n", length, "width", game->width);
	ft_printf("%-*s : %u\n", length, "height", game->height);
	ft_printf("%-*s : %hhu\n", length, "start_player", game->start_player);
	ft_printf("%-*s : %s\n", length, "is_debug",
		game->is_debug ? "true" : "false");
	ft_printf("%-*s : %s\n", length, "bot", str_from_bot(game->bot));
	ft_printf("%-*s : %s\n\n", length, "display",
		str_from_display(game->display));
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

	*game = new_game_state();
	parse_arguments(game, ac, av);
	print_game(game);
	game_state_init(game);
	run_game(game);
	game_state_clear(game);
	return (0);
}
