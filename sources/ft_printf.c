//
// HEADER
//

#define OCT "01234567"
#define DEC "0123456789"
#define HEX_L "0123456789abcdef"
#define HEX_U "0123456789ABCDEF"

#include "../includes/ft_printf.h"

static void	ftp_putchar(t_all *all, char c)
{
	write (1, &c, 1);
	all->cnt++;
}

static void	ftp_putstr(t_all *all, char *str)
{
	while (*str)
	{
		ftp_putchar(all, *str);	
		str++;
	}
}

static void	ftp_putnstr(t_all *all, char *str, int len)
{
	while (len > 0)
	{
		ftp_putchar(all, *str);
		str++;
		len--;
	}
}

static void	ftp_putwchar(t_all *all, wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	all->cnt++;
}

static void	ftp_putnwstr(t_all *all, wchar_t *str, int len)
{
		int	i;

		i = 0;
		while (*str && i < len)
		{
				if (i > len)
						break ;
				ftp_putwchar(all, *str);
				str++;
		}
}

static int	ftp_nbrlen(uintmax_t nbr, char *base)
{
		size_t b;
		int i;

	i = 0;
	b = ft_strlen(base);
	if (nbr == 0)
			return (1);
	while (nbr)
	{
			nbr = nbr / b;
			i++;
	}
	return (i);
}

static int	print_pad_left(t_all *all, int len)
{
	if (!all->right_pad && all->width)
	{
		while (all->width-- > len)
			ftp_putchar(all, ' ');
		return (1);
	}
	return (0);
}

static int	print_pad_right(t_all *all, int len)
{
		if (all->width)
		{
				while (all->width-- > len)
						ftp_putchar(all, ' ');
				return (1);
		}
		return(0);
}

static void	print_fpad_right(t_all *all, int len)
{
		if (all->width)
		{
				while (all->width-- > len)
						ftp_putchar(all, ' ');
		}
}

static void	print_zero_left(t_all *all, int precision, int i)
{
		while (i++ < precision)
				ftp_putchar(all, '0');
}

static int	pad_left(t_all *all, int len)
{
	if (all->precision && len < all->precision)
	{
			print_zero_left(all, all->precision, len);
			return (1);
	}
	else if (all->zero_pad && all->width && len < all->width)
	{
			print_zero_left(all, all->width, len);
			return (1);
	}
	print_pad_left(all, len);
	return (0);
}

static int	ftp_wstrlen(wchar_t *str)
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

static intmax_t	cast_signed_int(va_list arg, t_all *all)
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

static uintmax_t cast_unsigned_int(va_list arg, t_all *all)
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

static char	*get_prefix(t_all *all, int maj, char *p1, char *p2)
{
	if (all->prefix)
	{
		if (maj)
			return (p2);
		return (p1);
	}
	return ("");
}

void	printe(va_list arg, t_all *all, char c)
{
		(void)c;
		return ((void)printc(arg, all, '%'));
}

void	printo(va_list arg, t_all *all, char c)
{
		uintmax_t	nbr;
		int			len;
		int			maj;
		int			pad;
		char		*prefix;

		// pas de flag +
		// 0 ignoré si - ou si precision
		
		len = 0;
		pad = 0;
		maj = ((c == 'o') ? 0 : 1);
		nbr = cast_unsigned_int(arg, all);
		prefix = get_prefix(all, maj, "0", "0");
		len = ftp_nbrlen(nbr, OCT) + ft_strlen(prefix);
		pad = pad_left(all, len);
		ft_putstr(prefix);
		ft_putnnbr_base(nbr, len, 8, maj);
		all->cnt += len;
		if (!pad)
			print_pad_right(all, len);
}

void	printx(va_list arg, t_all *all, char c)
{
		uintmax_t	nbr;
		int			len;
		int 		maj;
		int			pad;
		char		*prefix;

		// pas de flag +
		// 0 ignoré si - ou si precision

		len = 0;
		pad = 0;
		maj = ((c == 'x') ? 0 : 1);
		nbr = cast_unsigned_int(arg, all);
		prefix = get_prefix(all, maj, "0x", "0X");
		len = ftp_nbrlen(nbr, HEX_L) + ft_strlen(prefix);
		pad = pad_left(all, len);
		ft_putstr(prefix);
		ft_putnnbr_base(nbr, len, 16, maj);
		all->cnt += len;
		if (!pad)
			print_pad_right(all, len);
}

void	printu(va_list arg, t_all *all, char c)
{
		int			pad;
		int			len;
		uintmax_t	nbr;

		// pas de flag #
		// pas de flag +
		// 0 ignoré si - ou précision

		(void)c;
		pad = 0;
		nbr = cast_unsigned_int(arg, all);
		len = ftp_nbrlen(nbr, DEC);
		pad = pad_left(all, len);
		ft_putnnbr_base(nbr, len, 10, 0);
		all->cnt += len;
		if (!pad)
			print_pad_right(all, len);
}

void	printws(va_list arg, t_all *all, char c)
{
		int		len;
		wchar_t *str;

		// pad de flag 0
		// pas de flag #
		// pas de flag +
		
		(void)c;
		if (!(str = va_arg(arg, wchar_t *)))
			str = ((all->precised == 0) ? L"(null)" : L"");
		len = ftp_wstrlen(str);
		if (all->precision && len > all->precision)
				len = all->precision;
		print_pad_left(all, len);
		ftp_putnwstr(all, str, len);
		print_pad_right(all, len);
}

void	prints(va_list arg, t_all *all, char c)
{
		int		len;
		char	*str;

		// pas de flag #
		// pad de flag 0
		// pas de flag +

		(void)c;
		if (!(all->length == LONG_INT))
		{
			if (!(str = va_arg(arg, char *)))
				str = ((all->precised == 0) ? "(null)" : "");
			len = ft_strlen(str);
			if (all->precision && len > all->precision)
				len = all->precision;
			print_pad_left(all, len);
			ftp_putnstr(all, str, len);
			print_pad_right(all, len);
			return ;
		}
		return (printws(arg, all, c));
}

void	printwc(va_list arg, t_all *all, char c)
{
		// pas de precision
		// pad de flag #
		// pad de flag 0
		// pad de flag +

		(void)c;
		print_pad_left(all, 1);
		ftp_putwchar(all, va_arg(arg, wint_t));
		print_pad_right(all, 1);
}

void	printc(va_list arg, t_all *all, char c)
{
		char	chr;

		// pas de precision
		// pad de flag #
		// pad de flag 0
		// pad de flag +

		(void)c;
		if (!(all->length == LONG_INT))
		{
			chr = ((c == '%') ? '%' : va_arg(arg, int));
			print_pad_left(all, 1);
			ftp_putchar(all, chr);
			print_pad_right(all, 1);
			return ;
		}
		return (printwc(arg, all, c));

}

static char *get_sign(t_all *all, intmax_t nbr)
{
		char *sign;

		sign = "";
		if (nbr < 0)
				sign = "-";
		else if (all->always_sign)
				sign = "+";
		else if (all->blank_sign)
				sign = " ";
		return (sign);
}

void	printi(va_list arg, t_all *all, char c)
{
		char			*prefix;
		int				len;
		int				padded;
		int				prefixed;
		intmax_t		nbr;

		(void)c;
		len = 0;
		padded = 0;
		prefixed = 0;
		prefix = NULL;
		nbr = cast_signed_int(arg, all);
		prefix = get_sign(all, nbr);
		if (nbr < 0)
				nbr = -nbr;
		len = ftp_nbrlen(nbr, DEC) + ft_strlen(prefix);

		// get nbr length
		if (all->zero_pad)
		{
				ftp_putstr(all, prefix);
				prefixed = 1;
		}
		// handle precision
		if (all->precision && (len > all->precision))
		{
				if (all->width < all->precision)
						len = all->precision;
		}
		else if (all->precision && (len < all->precision))
		{
				padded = 1;
				if (all->zero_pad == 1)
						print_zero_left(all, all->precision, len);
				else
						print_pad_left(all, len);
		}

		// handle width
		if (all->width && (all->width > len))
		{
				padded = 1;
				if (all->zero_pad)
						print_zero_left(all, all->width, len);
				else
						print_pad_left(all, len);
		}
		else if (all->width)
				print_pad_left(all, len);
		if (prefixed == 0)
				ftp_putstr(all, prefix);
		if (!nbr && !all->precision && all->precised)
				return ;
		ft_putnnbr(nbr, len);
		all->cnt += len;
		if (padded == 0 || all->right_pad)
		{
				if (all->right_pad)
						print_fpad_right(all, len);
				else
						print_pad_right(all, len);	
		}
}

void	printp(va_list arg, t_all *all, char c)
{
		uintmax_t	nbr;
		int			len;
		char		*prefix;

		(void)c;
		prefix = "";
		// set flag z a 1 ?
		nbr = cast_unsigned_int(arg, all);
		if (!nbr)
				len = 5;
		else
				prefix = "0x";
		len = ftp_nbrlen(nbr, HEX_L) + ft_strlen(prefix);
		if (all->precision && len > all->precision)
				len = all->precision;
		else if (all->precision && len < all->precision)
				print_zero_left(all, all->precision, len);
		else
				print_pad_left(all, len);
		if (!nbr)
				ft_putstr("(nil)");
		else
		{
				ftp_putstr(all, prefix);
				ft_putnnbr_base(nbr, len, 16, 0);
				all->cnt += len;
		}
		print_pad_right(all, len);
}

static int		parse(va_list arg, char *format)
{
		int 	ret;
		t_all	all;
		t_type 	tab;

		ret = 0;
		while (*format)
		{
				all.cnt = 0;
				if (*format == '%')
				{
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
