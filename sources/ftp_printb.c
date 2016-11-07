/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 19:50:57 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/21 19:52:24 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printb(va_list arg, t_all *all, char c)
{
	size_t		len;
	uintmax_t	nbr;

	nbr = cast_unsigned_int(arg, all);
	len = ft_nbrlen_base(nbr, "01");
	if (!nbr && all->precised && !all->precision)
		len = 0;
	put_prefix(all, get_prefix(all, c), len, 0);
	if ((!nbr && all->precised && !all->precision) || (!nbr && all->prefix))
		(void)nbr;
	else
	{
		ft_putnnbr_base(nbr, len, 2, 0);
		all->cnt += len;
	}
	if (all->right_pad)
	{
		if (all->prefix)
			len += 1;
		pad_width2(all, "", len, ' ');
	}
}
