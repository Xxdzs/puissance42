/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:41:29 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 23:48:43 by jates-           ###   ########.fr       */
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
	char			*player_name;
	unsigned		width;
	unsigned		height;
	char			jetons[3];
	enum			e_player
	{
		EMPTY,
		HUMAN,
		BOT
	}				start_player;
	enum e_bot		bot;
	enum e_display	display;
	bool			is_debug;
}				t_game_state;

t_game_state	new_game_state(void);
void			game_state_init(t_game_state *game);
void			game_state_clear(t_game_state *game);

uint8_t			bot_from_str(const char *str);
uint8_t			display_from_str(const char *str);
const char		*str_from_bot(uint8_t bot);
const char		*str_from_display(uint8_t display);

void			print_board(t_game_state *game);

#endif
