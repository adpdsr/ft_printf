/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:37:48 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/11 18:06:14 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnnbr_base_2(uintmax_t nb, int len, unsigned int base, int flag, int ref)
{
		if (ref == len)
				return ;
		if (nb >= base)
		{
				ft_putnnbr_base_2(nb / base, len, base, flag, ref++);
				ft_putnnbr_base_2(nb % base, len, base, flag, ref++);
		}
		else
		{
				if (nb < 10)
						ft_putchar(nb + '0');
				else
				{
						if (flag == 0)
								ft_putchar(nb - 10 + 'a');
						else
								ft_putchar(nb - 10 + 'A');
				}
		}
}

void	ft_putnnbr_base(uintmax_t n, int len, unsigned int base, int flag)
{
		ft_putnnbr_base_2(n, len, base, flag, 0);
}
