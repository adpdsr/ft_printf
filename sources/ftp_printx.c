/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:44:38 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/13 16:06:59 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*get_prefix(t_all *all, char c)
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

static void	ftp_putnchar(t_all *all, char c, int n)
{
	while (n-- > 0)
		ftp_putchar(all, c);
}

static void	pad_width2(t_all *all, char *prefix, unsigned int len, char c)
{
	all->width -= ft_strlen(prefix);
	if (all->precision > len)
		all->width -= all->precision;
	else
		all->width -= len;
	ftp_putnchar(all, c, all->width);
}

static void	pad_precision(t_all *all, unsigned int len)
{
	if (all->precision > len)
		ftp_putnchar(all, '0', all->precision - len);
}

static void	put_prefix(t_all *all, char *prefix, int len, int flag)
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

void		printx(va_list arg, t_all *all, char c)
{
	size_t			len;
	uintmax_t		nbr;
	unsigned int	maj;

	maj = (c == 'x') ? 0 : 1;
	nbr = cast_unsigned_int(arg, all);
	len = ft_nbrlen_base(nbr, "0123456789abcdef");
	if (nbr != 0 || all->widthed)
	{
		if (nbr == 0 && all->precised && !all->precision)
			len -= 1;
		put_prefix(all, get_prefix(all, c), len, 1);
	}
	if ((all->precised && all->precision) || (!all->precised))
	{
		ft_putnnbr_base(nbr, len, 16, maj);
		all->cnt += len;
	}
	if (all->right_pad)
		pad_width2(all, get_prefix(all, c), len, ' ');
}

void		printo(va_list arg, t_all *all, char c)
{
	size_t		len;
	uintmax_t	nbr;

	if (c == 'O')
		all->length = LONG_INT;
	nbr = cast_unsigned_int(arg, all);
	len = ft_nbrlen_base(nbr, "01234567");
	if (!nbr && all->precised && !all->precision)
		len = 0;
	put_prefix(all, get_prefix(all, c), len, 0);
	if ((!nbr && all->precised && !all->precision) || (!nbr && all->prefix))
		(void)nbr;
	else
	{
		ft_putnnbr_base(nbr, len, 8, 0);
		all->cnt += len;
	}
	if (all->right_pad)
	{
		if (all->prefix)
			len += 1;
		pad_width2(all, "", len, ' ');
	}
}

void	printu(va_list arg, t_all *all, char c)
{
	size_t		len;
	uintmax_t	nbr;

	if (c == 'U')
		all->length = LONG_INT;
	nbr = cast_unsigned_int(arg, all);
	len = ft_nbrlen_base(nbr, "0123456789");
	put_prefix(all, "", len, 1);
	if ((all->precised && all->precision) || (!all->precised))
	{
		ft_putnnbr_base(nbr, len, 10, 0);
		all->cnt += len;
	}
	if (all->right_pad)
		pad_width2(all, "", len, ' ');
}

void	printp(va_list arg, t_all *all, char c)
{
	size_t			len;
	intmax_t	nbr;

	(void)c;
	nbr = va_arg(arg, intmax_t);
	len = ft_nbrlen_base(nbr, "0123456789abcdef");
	put_prefix(all, "0x", len, 1);
	if (all->right_pad)
		ftp_putstr(all, "0x");
	if ((all->precised && all->precision) || (!all->precised))
	{
		ft_putnnbr_base(nbr, len, 16, 0);
		all->cnt += len;
	}
	if (all->right_pad)
		pad_width2(all, "0x", len, ' ');
}

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

void	printi(va_list arg, t_all *all, char c)
{
	size_t			len;
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
	if (!nbr && all->precised && !all->precision) /* NEW */
		len -= 1;
	put_prefix(all, prefix, len, 1);	
	if (nbr || (all->precised && all->precision) || (!all->precised)) /* NEW */
	{
		ft_putnnbr_base(nbr, len, 10, 0);
		all->cnt += len;
	}
	if (all->right_pad)
		pad_width2(all, prefix, len, ' ');
}
