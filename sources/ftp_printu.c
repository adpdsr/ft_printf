/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:59:11 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 16:59:25 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printu(va_list arg, t_all *all, char c)
{
	size_t		len;
	uintmax_t	nbr;

	if (c == 'U')
		all->length = LONG_INT;
	nbr = cast_unsigned_int(arg, all);
	len = ft_nbrlen_base(nbr, "0123456789");
	put_prefix(all, "", len, 1);
	if ((all->precised && all->precision) || (!all->precised))
	{
		ft_putnnbr_base(nbr, len, 10, 0);
		all->cnt += len;
	}
	if (all->right_pad)
		pad_width2(all, "", len, ' ');
}
