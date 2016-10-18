/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:37:48 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 15:48:02 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnnbr_base_2(uintmax_t nb, int len, unsigned int base, int f)
{
	if (!len)
		return ;
	if (nb >= base)
	{
		ft_putnnbr_base_2(nb / base, len--, base, f);
		ft_putnnbr_base_2(nb % base, len--, base, f);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
		{
			if (f == 0)
				ft_putchar(nb - 10 + 'a');
			else
				ft_putchar(nb - 10 + 'A');
		}
	}
}

void		ft_putnnbr_base(uintmax_t n, int len, unsigned int base, int f)
{
	ft_putnnbr_base_2(n, len, base, f);
}
