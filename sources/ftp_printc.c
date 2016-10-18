/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:54:38 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 16:55:03 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printc(va_list arg, t_all *all, char c)
{
	char s;

	if (all->length == LONG_INT)
		return (printwc(arg, all, c));
	s = ((is_type(c) == 0) ? c : va_arg(arg, int));
	if (!all->right_pad && all->widthed && (all->width > 1))
		pad_width(all, 1, (all->zero_pad) ? '0' : ' ');
	ftp_putchar(all, s);
	if (all->right_pad && all->widthed && (all->width > 1))
		pad_width(all, 1, (all->zero_pad) ? '0' : ' ');
}
