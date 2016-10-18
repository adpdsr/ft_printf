/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:02:11 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 17:03:27 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_prefix(t_all *all, char c)
{
	if (all->prefix)
	{
		if (c == 'x')
			return ("0x");
		else if (c == 'X')
			return ("0X");
		else
			return ("0");
	}
	return ("");
}

void	put_prefix(t_all *all, char *prefix, int len, int flag)
{
	if (!all->right_pad)
	{
		if (all->zero_pad && !all->precision)
		{
			ftp_putstr(all, prefix);
			pad_width2(all, prefix, len, '0');
		}
		else
		{
			pad_width2(all, prefix, len, ' ');
			if (!flag)
			{
				if (!all->precision)
					ftp_putstr(all, prefix);
			}
			else
				ftp_putstr(all, prefix);
		}
	}
	else if (all->prefix || all->always_sign)
		ftp_putstr(all, prefix);
	pad_precision(all, len);
}
