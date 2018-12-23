/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:10:07 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 12:05:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include "libft.h"

#include <stdbool.h>
#include <stdint.h>

static const char *const
g_bots_str[] = {
	"NONE",
	"PROMPT",
	"RANDOM",
	"GREEDY",
	"MAXMIN"
};

static const char *const
g_displays_str[] = {
	"NONE",
	"SIMPLE",
	"NUMBERS"
};

uint8_t		bot_from_str(const char *str)
{
	uint8_t		answer;

	answer = BOTS_COUNT;
	while (--answer > 0 && ft_strcmp(str, g_bots_str[answer]))
		;
	return (answer);
}

const char	*str_from_bot(uint8_t bot)
{
	if (bot < BOTS_COUNT)
		return (g_bots_str[bot]);
	return (NULL);
}

uint8_t		display_from_str(const char *str)
{
	uint8_t		answer;

	answer = DISPLAYS_COUNT;
	while (--answer > 0 && ft_strcmp(str, g_displays_str[answer]))
		;
	return (answer);
}

const char	*str_from_display(uint8_t display)
{
	if (display < DISPLAYS_COUNT)
		return (g_displays_str[display]);
	return (NULL);
}

const char	*str_from_player(uint8_t player)
{
	const char *const players_str[] = {
		"EMPTY",
		"Human",
		"Bot"
	};

	if (player <= BOT)
		return (players_str[player]);
	return (NULL);
}
