/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:58:54 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/22 15:35:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "libft.h"
#include "ft_printf.h"
#include "ft_array.h"

#include <stdbool.h>

/*
** Options without parameters
** -
** returns true if the name matches with an existing option,
** false otherwise
*/

static bool	set_option(t_game_state *game, const char* name, bool is_long)
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

static void	set_option_wp(t_game_state *game, const char* name,
						const char* value, bool is_long)
{
	if (*name == 'w' && !(is_long && ft_strcmp(name, "width")))
		game->width = ft_atoi(value);
	else if (*name == 'h' && !(is_long && ft_strcmp(name, "height")))
		game->height = ft_atoi(value);
	else if (*name == 'b' && !(is_long && ft_strcmp(name, "bot")))
		game->bot = bot_from_str(value);
	else if (*name == 'd' && !(is_long && ft_strcmp(name, "display")))
		game->display = display_from_str(value);
}

void		print_game(t_game_state *game)
{
	ft_printf("width : %u\n", game->width);
	ft_printf("height : %u\n", game->height);
	ft_printf("start_player : %hhu\n", game->start_player);
	ft_printf("is_debug ? %s\n", game->is_debug ? "true" : "false");
	ft_printf("bot : %s\n", str_from_bot(game->bot));
	ft_printf("display : %s\n", str_from_display(game->display));
}

int			main(int ac, char** av)
{
	t_game_state	game;
	bool			is_long;
	const char		*name;
	const char		*value;

	game = (t_game_state){NEW_ARRAY(enum e_player), 7, 6, HUMAN, false};
	while (--ac > 0 && *++av != NULL)
	{
		is_long = false;
		if (**av != '-')
			continue ;
		if (*++*av == '-' && (is_long = true) && *++*av == '\0')
			break ;
		name = *av;

		if (is_long)
			ft_printf("Option \"%s\"\n", name);
		else
			ft_printf("Option '%c'\n", *name);

		if (set_option(&game, name, is_long))
			continue ;

		if (is_long)
			value = (value = ft_strchr(*av, '=')) == NULL && ac-- ?
					 *++av : value + 1;
		else
			value = (*++*av == '\0' && ac-- ? *++av : *av);
		if (value == NULL)
			value = "";

		ft_printf("\twith argument \"%s\"\n", value);
		set_option_wp(&game, name, value, is_long);
	}
//	new_game_state(&game);
	print_game(&game);
	return (0);
}
