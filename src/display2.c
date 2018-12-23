/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:07:04 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/23 22:55:37 by jates-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include "puissance.h"
#include "ft_printf.h"

#include <stdlib.h>
#include <unistd.h>

/*
** Function which prints a ligne
*/

void			draw_ligne(size_t size, char c)
{
	char str[2048];

	if (size < 2047)
		ft_memset(str, c, size);
	else
	{
		ft_memset(str, c, 2048);
		while (size > 2047 && (size -= 2048))
			write(1, &c, 2048);
	}
	str[size] = '\n';
	write(1, str, size + 1);
}

/*
** custom made function to sleep
*/

void			ft_sleep(unsigned tempo)
{
	unsigned short idx;

	idx = 1;
	while (tempo--)
	{
		while (idx++)
			;
		idx = 1;
	}
}
