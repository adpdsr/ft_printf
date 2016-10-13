/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:22:53 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/13 14:23:09 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ftp_putchar(t_all *all, char c)
{
	//if (ft_isprint(c)) // a virer de source makefile et .h
	write (1, &c, 1);
	all->cnt++;
}

void	ftp_putstr(t_all *all, char *s)
{
	while (*s)
	{
		ftp_putchar(all, *s);
		s++;
	}
}

void	ftp_putnstr(t_all *all, char *s, int len)
{
	while (len > 0)
	{
		ftp_putchar(all, *s);
		len--;
		s++;
	}
}
