/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jates- <jates-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:41:29 by jates-            #+#    #+#             */
/*   Updated: 2018/12/22 15:06:16 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

#include "ft_array.h"

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

#endif
