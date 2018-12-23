/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:58:54 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 21:09:52 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "libft.h"
#include "ft_printf.h"
#include "ft_array.h"

static char *tmp_cell_to_string(uint8_t *cell)
{
	const char *str = str_from_player(*cell);

	return (ft_strdup(str ? str : "!"));
}

void		print_game_state(const t_game_state *game)
{
	const unsigned length = 12;

	ft_printf("\n%-*s : %s\n", length, "player_name", game->player_name);
	ft_printf("%-*s : %u\n", length, "width", game->width);
	ft_printf("%-*s : %u\n", length, "height", game->height);
	ft_printf("%-*s : %s\n", length, "start_player", str_from_player(game->start_player));
	ft_printf("%-*s : %c\n", length, "start jeton", game->jetons[game->start_player]);
	ft_printf("%-*s : %s\n", length, "bot", str_from_bot(game->bot));
	ft_printf("%-*s : %s\n", length, "display",
		str_from_display(game->display));
	ft_printf("%-*s : %s\n", length, "is_debug",
		game->is_debug ? "true" : "false");
	ft_printf("%s\n\n", fta_string((const t_array *)game, tmp_cell_to_string));
}
