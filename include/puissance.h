/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:41:29 by jates-            #+#    #+#             */
/*   Updated: 2018/12/28 16:56:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "ft_array.h"

# include <stdbool.h>
# include <stdint.h>

enum		e_display
{
	DISPLAY_NONE,
	DISPLAY_SIMPLE,
	DISPLAY_NUMBERS,
	DISPLAYS_COUNT
};

enum		e_bot
{
	BOT_NONE,
	BOT_PROMPT,
	BOT_RANDOM,
	BOT_GREEDY,
	BOT_MAXMIN,
	BOTS_COUNT
};

enum		e_player
{
	EMPTY,
	HUMAN,
	BOT
};

typedef struct	s_game_state
{
	t_array			board;
	const char		*player_name;
	unsigned		width;
	unsigned		height;
	char			jetons[3];
	enum e_player	start_player;
	enum e_player	winner;
	enum e_bot		bot;
	enum e_display	display;
	bool			is_debug;
	bool			is_colored;
	bool			is_animated;
}				t_game_state;

/*
** Constructor, init and destructor for the game_state struct
*/

t_game_state	new_game_state(void);
void			game_state_init(t_game_state *game);
void			game_state_clear(t_game_state *game);

/*
** Game functions
*/

void			run_game(t_game_state *game);
void			print_board(const t_game_state *game);
bool			is_move_possible(const t_game_state *game, unsigned col);
unsigned		play_bot(t_game_state *game);
unsigned		play_prompt(t_game_state *game);
bool			iswin_case(const t_game_state *game, int lig,
				int col, int8_t player);
void			draw_ligne(size_t size, char c);
void			ft_sleep(unsigned tempo);

/*
** Enum conversion functions
*/

uint8_t			bot_from_str(const char *str);
uint8_t			display_from_str(const char *str);
const char		*str_from_bot(uint8_t bot);
const char		*str_from_display(uint8_t display);
const char		*str_from_player(uint8_t player);

/*
** Type of bots
*/

unsigned		play_greedy(t_game_state *game);
unsigned		play_random(t_game_state *game);
unsigned		play_prompt(t_game_state *game);
unsigned		play_bot(t_game_state *game);

/*
** Info fetching functions
*/

void			get_player_name(t_game_state *game);
int				get_player_move(t_game_state *game);
bool			put_jeton_gravity(t_game_state *game,
			unsigned col, uint8_t player);
bool			put_jeton(t_game_state *game,
			unsigned col, uint8_t player);
unsigned		column_top(const t_game_state *game, unsigned column);
t_array			create_layer(const t_game_state *game);

/*
** Misc. utils
*/

void			do_nothing_at_all();
void			print_game_state(const t_game_state *game);

#endif
