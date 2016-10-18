/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printwc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:55:17 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 16:55:34 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printwc(va_list arg, t_all *all, char c)
{
	size_t	len;
	wchar_t	s;

	(void)c;
	s = va_arg(arg, wchar_t);
	len = ft_nwstrlen(&s, 1);
	if (!all->right_pad && all->widthed && (all->width > 1))
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
	ftp_putwchar(all, s);
	if (all->right_pad && all->widthed && (all->width > 1))
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
}
