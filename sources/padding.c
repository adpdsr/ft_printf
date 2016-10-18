/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:04:26 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 17:07:52 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pad_width2(t_all *all, char *prefix, unsigned int len, char c)
{
	all->width -= ft_strlen(prefix);
	if (all->precision > len)
		all->width -= all->precision;
	else
		all->width -= len;
	ftp_putnchar(all, c, all->width);
}

void	pad_precision(t_all *all, unsigned int len)
{
	if (all->precision > len)
		ftp_putnchar(all, '0', all->precision - len);
}
