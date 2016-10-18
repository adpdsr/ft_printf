/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:59:31 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 17:00:02 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printp(va_list arg, t_all *all, char c)
{
	size_t		len;
	intmax_t	nbr;

	(void)c;
	nbr = va_arg(arg, intmax_t);
	len = ft_nbrlen_base(nbr, "0123456789abcdef");
	put_prefix(all, "0x", len, 1);
	if (all->right_pad)
		ftp_putstr(all, "0x");
	if ((all->precised && all->precision) || (!all->precised))
	{
		ft_putnnbr_base(nbr, len, 16, 0);
		all->cnt += len;
	}
	if (all->right_pad)
		pad_width2(all, "0x", len, ' ');
}
