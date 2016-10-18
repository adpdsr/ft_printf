/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:23:11 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 15:40:23 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ftp_putwchar(t_all *all, wchar_t c)
{
	if (c <= 0x7F && (all->cnt += 1))
		ft_putchar(c);
	else if (c <= 0x7FF && (all->cnt += 2))
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF && (all->cnt += 3))
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF && (all->cnt += 4))
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

void	ft_putwchar(t_all *all, wchar_t chr)
{
	if (chr <= 0x7F)
		ftp_putchar(all, chr);
	else if (chr <= 0x7FF)
	{
		ftp_putchar(all, (chr >> 6) + 0xC0);
		ftp_putchar(all, (chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ftp_putchar(all, (chr >> 12) + 0xE0);
		ftp_putchar(all, ((chr >> 6) & 0x3F) + 0x80);
		ftp_putchar(all, (chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ftp_putchar(all, (chr >> 18) + 0xF0);
		ftp_putchar(all, ((chr >> 12) & 0x3F) + 0x80);
		ftp_putchar(all, ((chr >> 6) & 0x3F) + 0x80);
		ftp_putchar(all, (chr & 0x3F) + 0x80);
	}
}

void	ftp_putnwstr(t_all *all, wchar_t *str, int len)
{
	int	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar(all, *str++);
	}
}
