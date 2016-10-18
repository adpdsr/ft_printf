/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nwstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:45:30 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 17:39:42 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	inc(int *a, int *b, int inc)
{
	*a += inc;
	*b -= inc;
}

int			ft_nwstrlen(wchar_t *s, int n)
{
	int i;

	i = 0;
	while (*s && (n > 0))
	{
		if (*s < (1 << 7))
			inc(&i, &n, 1);
		else if (*s < (1 << 11))
			inc(&i, &n, 2);
		else if (*s < (1 << 16))
			inc(&i, &n, 3);
		else if (*s < (1 << 21))
			inc(&i, &n, 4);
		s++;
		if (i > n)
			n--;
	}
	return (i);
}
