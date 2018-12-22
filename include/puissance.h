/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:41:29 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 15:40:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "ft_array.h"
# include <stdbool.h>
# include <stdint.h>

enum	e_display
{
	DISPLAY_NONE,
	DISPLAY_SIMPLE,
	DISPLAYS_COUNT
};

enum	e_bot
{
	BOT_NONE,
	BOT_PROMPT,
	BOT_RANDOM,
	BOT_GREEDY,
	BOT_MAXMIN,
	BOTS_COUNT
};

typedef struct	s_game_state
{
	t_array			board;
	unsigned		width;
	unsigned		height;
	enum			e_player
	{
		EMPTY,
		HUMAN,
		BOT
	}				start_player;
	bool			is_debug;
	enum e_bot		bot;
	enum e_display	display;
}				t_game_state;

#endif
