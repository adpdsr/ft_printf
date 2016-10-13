/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:56:55 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/13 18:37:26 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	cast_signed_int(va_list arg, t_all *all)
{
	intmax_t nbr;

	nbr = va_arg(arg, intmax_t);
	if (all->length == CHAR)
		nbr = (char)nbr;
	else if (all->length == LONG_LONG_INT)
		nbr = (long long int)nbr;
	else if (all->length == SHORT_INT)
		nbr = (short int)nbr;
	else if (all->length == LONG_INT)
		nbr = (long int)nbr;
	else if (all->length == INTMAXT)
		nbr = (intmax_t)nbr;
	else if (all->length == SIZET)
		nbr = (ssize_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t cast_unsigned_int(va_list arg, t_all *all)
{
	uintmax_t nbr;

	nbr = va_arg(arg, uintmax_t);
	if (all->length == CHAR)
		nbr = (unsigned char)nbr;
	else if (all->length == LONG_LONG_INT)
		nbr = (unsigned long long int)nbr;
	else if (all->length == SHORT_INT)
		nbr = (unsigned short int)nbr;
	else if (all->length == LONG_INT)
		nbr = (unsigned long int)nbr;
	else if (all->length == INTMAXT)
		nbr = (uintmax_t)nbr;
	else if (all->length == SIZET)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

void	printe(va_list arg, t_all *all, char c)
{
	(void)c;
	return ((void)printc(arg, all, c));
}

static int		parse(va_list arg, char *format)
{
	int 	ret; // a virer
	t_all	all;
	t_type 	tab;

	ret = 0;
	while (*format)
	{
		all.cnt = 0;
		if (*format == '%')
		{
			if (!(*(format + 1)))
				return (0);
			format++;
			ft_bzero(&all, sizeof(t_all));
			format = get_flag(&format, &all);
			format = get_width(&format, &all);
			format = get_precision(&format, &all);
			format = get_length(&format, &all);
			tab = get_type(*format);
			tab(arg, &all, *format);
		}
		else
			ftp_putchar(&all, *format);
		ret += all.cnt;
		format++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int	ret;
	va_list	arg;

	va_start(arg, format);
	ret = parse(arg, (char *)format);
	va_end(arg);
	return (ret);
}
