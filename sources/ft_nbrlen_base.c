/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:30:30 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/11 21:14:46 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_nbrlen_base(uintmax_t n, char *base)
{
	int		i;
	size_t	b;

	i = 0;
	b = ft_strlen(base);
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / b;
		i++;
	}
	return (i);
}
