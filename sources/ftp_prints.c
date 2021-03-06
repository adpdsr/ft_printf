/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_prints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:11:37 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 16:57:28 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			pad_width(t_all *all, unsigned int len, char c)
{
	while (len < all->width)
	{
		ftp_putchar(all, c);
		len++;
	}
}

void			prints(va_list arg, t_all *all, char c)
{
	size_t		len;
	char		*s;

	if (all->length == LONG_INT)
		return (printws(arg, all, c));
	if (!(s = va_arg(arg, char *)))
		s = ((all->precised == 0) ? "(null)" : "");
	len = ((all->precised) ? ft_nstrlen(s, all->precision) : ft_strlen(s));
	if (!all->right_pad && all->widthed && (all->width > len))
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
	ftp_putnstr(all, s, len);
	if (all->right_pad && all->widthed && (all->width > len))
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
}
