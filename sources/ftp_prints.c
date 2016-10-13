/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_prints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:11:37 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/13 18:30:37 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_nstrlen(char *s, unsigned int n)
{
	size_t i;

	i = 0;
	while (*s && i < n)
	{
		s++;
		i++;
	}
	return (i);
}

void	pad_width(t_all *all, unsigned int len, char c)
{
	while (len < all->width)
	{
		ftp_putchar(all, c);
		len++;
	}
}

static int  ft_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str < (1 << 7))
			i += 1;
		else if (*str < (1 << 11))
			i += 2;
		else if (*str < (1 << 16))
			i += 3;
		else if (*str < (1 << 21))
			i += 4;
		str++;
	}
	return (i);
}

static int  ft_nwstrlen(wchar_t *str, int len)
{
	int i;

	i = 0;
	while (*str && (len > 0))
	{
		if (*str < (1 << 7))
		{
			i += 1;
			len -= 1;
		}
		else if (*str < (1 << 11))
		{
			i += 2;
			len -= 2;
		}
		else if (*str < (1 << 16))
		{
			i += 3;
			len -= 3;
		}
		else if (*str < (1 << 21))
		{
			i += 4;
			len -= 4;
		}
		str++;
		if (i > len)
			len--;
	}
//	printf("ret = %d\n", i);
	return (i);
}

void		prints(va_list arg, t_all *all, char c)
{
	size_t		len;
	char	*s;

	if (all->length == LONG_INT)
		return (printws(arg, all, c));
	if (!(s = va_arg(arg, char *)))
		s = ((all->precised == 0) ? "(null)" : "");
	len = ((all->precised) ? ft_nstrlen(s, all->precision) : ft_strlen(s));
	if (!all->right_pad && all->widthed && (all->width > len)) // si pas de padding a droite et que width va modifier le champ
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
	ftp_putnstr(all, s, len);
	if (all->right_pad && all->widthed && (all->width > len)) // si padding a droite et que width va modifier le champ
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
}

void		printc(va_list arg, t_all *all, char c)
{
	char	s;

	if (all->length == LONG_INT)
		return (printwc(arg, all, c));
	s = ((is_type(c) == 0) ? c : va_arg(arg, int));
	if (!all->right_pad && all->widthed && (all->width > 1)) // si pas de padding a droite et que width va modifier le champ
		pad_width(all, 1, (all->zero_pad) ? '0' : ' ');
	ftp_putchar(all, s);
	if (all->right_pad && all->widthed && (all->width > 1)) // si padding a droite et que width va modifier le champ
		pad_width(all, 1, (all->zero_pad) ? '0' : ' ');
}

void		printwc(va_list arg, t_all *all, char c)
{
	size_t		len;
	wchar_t	s;

	(void)c;
	s = va_arg(arg, wchar_t);
	len = ft_nwstrlen(&s, 1);
	if (!all->right_pad && all->widthed && (all->width > 1)) // si pas de padding a droite et que width va modifier le champ
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
	ftp_putwchar(all, s);
	if (all->right_pad && all->widthed && (all->width > 1)) // si padding a droite et que width va modifier le champ
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');	
}

void    printws(va_list arg, t_all *all, char c)
{
	size_t     len;
	wchar_t *s;

	(void)c;
	if (!(s = va_arg(arg, wchar_t *)))
		s = ((all->precised == 0) ? L"(null)" : L"");
//	printf("prec = %d\n", all->precision);
	len = ((all->precised) ? ft_nwstrlen(s, all->precision) : ft_wstrlen(s));
//	printf("len = %zu\n", len);
	//printf("cnt = %d\n", all->cnt);
	if (!all->right_pad && all->widthed && (all->width > len)) // si pas de padding a droite et que width va modifier le champ
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
	ftp_putnwstr(all, s, len);
	if (all->right_pad && all->widthed && (all->width > len)) // si padding a droite et que width va modifier le champ
		pad_width(all, len, (all->zero_pad) ? '0' : ' ');
	//printf("cnt = %d\n", all->cnt);
}
