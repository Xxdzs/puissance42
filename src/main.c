/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:58:54 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 14:10:13 by jates-           ###   ########.fr       */
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
** Options without parameters
**
** returns true if the name matches with an existing option,
** false otherwise
*/

static bool	set_option(t_game_state *game, const char *name, bool is_long)
{
	if (is_long && !ft_strcmp(name, "debug"))
		game->is_debug = true;
	else if (*name == 'c' && !(is_long && ft_strcmp(name, "color")))
		game->is_colored = true;
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

/*
** Sets the environnement from the program arguments
*/

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
	if (game->is_debug)
		print_game_state(game);
	run_game(game);
	game_state_clear(game);
	return (0);
}
