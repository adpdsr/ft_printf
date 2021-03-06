/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:44:38 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 17:05:44 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printx(va_list arg, t_all *all, char c)
{
	size_t			len;
	uintmax_t		nbr;
	unsigned int	maj;

	maj = (c == 'x') ? 0 : 1;
	nbr = cast_unsigned_int(arg, all);
	len = ft_nbrlen_base(nbr, "0123456789abcdef");
	if (nbr != 0 || all->widthed)
	{
		if (nbr == 0 && all->precised && !all->precision)
			len -= 1;
		put_prefix(all, get_prefix(all, c), len, 1);
	}
	if ((all->precised && all->precision) || (!all->precised))
	{
		ft_putnnbr_base(nbr, len, 16, maj);
		all->cnt += len;
	}
	if (all->right_pad)
		pad_width2(all, get_prefix(all, c), len, ' ');
}
