/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:41:29 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 12:56:14 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_game_state
{
	t_array			board;
	unsigned		width;
	unsigned		height;
	enum	 
	{
		EMPTY,
		HUMAN,
		BOT
	}				start_player;		
}				t_game_state;
