/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:55:41 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 17:23:06 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printws(va_list arg, t_all *all, char c)
{
	size_t	len;
	wchar_t	*s;

	(void)c;
	if (!(s = va_arg(arg, wchar_t *)))
		s = ((all->precised == 0) ? L"(null)" : L"");
	len = ((all->precised) ? ft_nwstrlen(s, all->precision) : ft_wstrlen(s));
	if (!all->right_pad && all->widthed && (all->width > len))
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
	ftp_putnwstr(all, s, len);
	if (all->right_pad && all->widthed && (all->width > len))
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
}
