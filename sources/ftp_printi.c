/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:00:09 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 17:00:26 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*get_signed_prefix(t_all *all, intmax_t nbr)
{
	if (nbr < 0)
		return ("-");
	else if (nbr >= 0 && all->always_sign)
		return ("+");
	else if (all->blank_sign)
		return (" ");
	return ("");
}

void		printi(va_list arg, t_all *all, char c)
{
	size_t		len;
	char		*prefix;
	intmax_t	nbr;

	if (c == 'D')
		all->length = LONG_INT;
	nbr = cast_signed_int(arg, all);
	prefix = get_signed_prefix(all, nbr);
	if (nbr < 0)
	{
		nbr = -nbr;
		all->prefix = 1;
	}
	len = ft_nbrlen_base(nbr, "0123456789");
	if (!nbr && all->precised && !all->precision)
		len -= 1;
	put_prefix(all, prefix, len, 1);
	if (nbr || (all->precised && all->precision) || (!all->precised))
	{
		ft_putnnbr_base(nbr, len, 10, 0);
		all->cnt += len;
	}
	if (all->right_pad)
		pad_width2(all, prefix, len, ' ');
}
