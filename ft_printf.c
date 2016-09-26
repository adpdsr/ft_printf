//
// HEADER
//

#include "ft_printf.h"

static void	ft_putnbr_base(int nbr, char *base, size_t baselen)
{
		if (nbr >= baselen)
		{
				ft_putnbr_base(nbr / baselen, base, baselen);
				ft_putnbr_base(nbr % baselen, base, baselen);
		}
		else
				ft_putchar(base[nbr]);
}

static int	is_flag(char c)
{
		if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
				return (1);
		return (0);
}

static int	is_length(char c)
{
		if (c == 'h' || c == 'l' | c == 'j' || c == 'z')
				return (1);
		return (0);
}

static char	*get_flag(char **format, t_all *all)
{
		while (*format)
		{
				if (is_flag(**format))
				{
						if (**format == '#')
								all->prefix = 1;
						else if (**format == '0')
								all->zero_pad = 1;
						else if (**format == '-')
								all->right_pad = 1;
						else if (**format == ' ')
								all->blank_sign = 1;
						else if (**format == '+')
								all->always_sign = 1;
						if (all->right_pad == 1)
								all->zero_pad = 0;
						(*format)++;
				}
				else
						break;
		}
		return (*format);
}

static char *get_width(char **format, t_all *all)
{
		if (ft_isdigit(**format) && **format != '0')
		{
				while (ft_isdigit(**format))
				{
						all->width = all->width * 10 + ((**format) - '0');
						(*format)++;
				}
		}
		return (*format);
}

static char *get_precision(char **format, t_all *all)
{
		if (**format == '.')
		{
				(*format)++;
				while (ft_isdigit(**format))
				{
						all->precision = all->precision * 10 + ((**format) - '0');
						(*format)++;
				}
		}
		return (*format);
}

static char	*get_length(char **format, t_all *all)
{
		if (is_length(**format))
		{
				if (ft_strnstr(*format, "hh", 2))
				{
						all->length = CHAR;
						(*format)++;
				}
				else if (ft_strnstr(*format, "ll", 2))
				{
						all->length = LONG_LONG_INT;
						(*format)++;
				}
				else if (**format == 'h')
						all->length = SHORT_INT;
				else if (**format == 'l')
						all->length = LONG_INT;
				else if (**format == 'j')
						all->length = INTMAXT;
				else if (**format == 'z')
						all->length = SIZET;
				(*format)++;
		}
		return (*format);
}

static void	ft_putnnbr_2(uintmax_t nb, int len, int ref)
{
		if (ref == len)
				return ;
		if (nb >= 10)
		{
				ft_putnnbr_2(nb / 10, len, ref++);
				ft_putchar((nb % 10) + '0');
		}
		else
				ft_putchar(nb + '0');
}

static void	ft_putnnbr(uintmax_t n, int len)
{
		ft_putnnbr_2(n, len, 0);
}

static void	ft_putnnbr_base_2(uintmax_t nb, int len, int base, int flag, int ref)
{
		if (ref == len)
				return ;
		if (nb >= base)
		{
				ft_putnnbr_base_2(nb / base, len, base, flag, ref++);
				ft_putnnbr_base_2(nb % base, len, base, flag, ref++);
		}
		else
		{
				if (nb < 10)
						ft_putchar(nb + '0');
				else
				{
						if (flag == 0)
								ft_putchar(nb - 10 + 'a');
						else
								ft_putchar(nb - 10 + 'A');
				}
		}
}

static void	ft_putnnbr_base(uintmax_t n, int len, int base, int flag)
{
		ft_putnnbr_base_2(n, len, base, flag, 0);
}

static int	prints(va_list arg, t_all *all)
{
		char	*str;
		int		str_len;

		// handle null case

		// handle precision
		str = va_arg(arg, char *);	//
		if (!str)					// ternaire
				str = "(null)";		//
		str_len = ft_strlen(str);
		if (all->precision && str_len > all->precision)
				str_len = all->precision;

		// handle_width
		if (!all->right_pad)
		{
				if (all->width)
				{
						while ((all->width - str_len))
						{
								ft_putchar(' ');
								all->width--;
						}
				}
				ft_putnstr(str, str_len);
		}
		else
		{
				ft_putnstr(str, str_len);
				if (all->width)
				{
						while ((all->width - str_len))
						{
								ft_putchar(' ');
								all->width--;
						}
				}
		}
		return (0); // retval
}

static int	printc(va_list arg, t_all *all)
{
		//		if (all->length == L)
		//		{
		//			wchar_t type !
		//		}
		// handle width - no precision needed
		if (!all->right_pad)
		{
				while (all->width-- > 1)
						ft_putchar(' ');
				ft_putchar(va_arg(arg, int));
		}
		else
		{
				ft_putchar(va_arg(arg, int));
				while (all->width-- > 1)
						ft_putchar(' ');
		}
		return (0); // retval
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

static intmax_t	cast_unsigned_int(va_list arg, t_all *all)
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

static int	ft_printf_nbrlen(uintmax_t nbr, int base_len)
{
		unsigned int i;

		i = 0;
		if (nbr == 0)
				return (1);
		while (nbr)
		{
				nbr = nbr / base_len;
				i++;
		}
		return (i);
}

static int	printi(va_list arg, t_all *all)
{
		intmax_t		nbr;
		char			*prefix;
		int				nbr_len;

		nbr_len = 0;
		nbr = cast_signed_int(arg, all);

		// handle sign
		if (nbr < 0)
		{
				nbr = -nbr;
				prefix = "-";
		}
		else if (all->always_sign)
				prefix = "+";
		else if (all->blank_sign)
				prefix = " ";
		else
				prefix = "";

		// handle precision
		nbr_len = ft_printf_nbrlen(nbr, 10) + ft_strlen(prefix);
		if (all->precision && nbr_len > all->precision)
				nbr_len = all->precision;

		// handle width
		if (!all->right_pad)
		{
				if (all->width)
				{
						while ((all->width - nbr_len) > 0)
						{
								ft_putchar(' ');
								all->width--;
						}
				}
				// print result
				ft_putstr(prefix);
				ft_putnnbr(nbr, nbr_len);
		}
		else
		{
				// print result
				ft_putstr(prefix);
				ft_putnnbr(nbr, nbr_len);
				if (all->width)
				{
						while ((all->width - nbr_len) > 0)
						{
								ft_putchar(' ');
								all->width--;
						}
				}
		}
		return (0); // retval
}

static int	printx(va_list arg, t_all *all, int base)
{
		uintmax_t	nbr;
		int		nbr_len;

		nbr_len = 0;
		nbr = cast_unsigned_int(arg, all);

		// handle precision
		nbr_len = ft_printf_nbrlen(nbr, 16); // + ft_strlen(prefix) ?
		if (all->precision && nbr_len > all->precision)
				nbr_len = all->precision;

		// handle width
		if (!all->right_pad)
		{
				if (all->width)
				{
						while ((all->width - nbr_len) > 0)
						{
								ft_putchar(' ');
								all->width--;
						}
				}
				ft_putnnbr_base(nbr, nbr_len, 16, base);
		}
		else
		{
				ft_putnnbr_base(nbr, nbr_len, 16, base);
				if (all->width)
				{
						while ((all->width - nbr_len) > 0)
						{
								ft_putchar(' ');
								all->width--;
						}
				}
		}

		// print result
		//ft_putstr(prefix);
		return (0);
}

static int	printe(t_all *all)
{
	if (!all->right_pad)
	{
		if (all->width)
		{
			while ((all->width - 1) > 0)
			{
				ft_putchar(' ');
				all->width--;
			}
		}
		ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		if (all->width)
		{
			while ((all->width - 1) > 0)
			{
				ft_putchar(' ');
				all->width--;
			}
		}
	}
}

static int	parse(va_list arg, const char *format)
{
		int		c;
		int		p;
		char	*str;
		t_all	all;

		p = 0;
		c = 0;
		while (*format)
		{
				if (*format == '%')
				{
						format++;
						ft_bzero(&all, sizeof(t_all));
						format = get_flag((char **)&format, &all);
						format = get_width((char **)&format, &all);
						format = get_precision((char **)&format, &all);
						format = get_length((char **)&format, &all);
						if (*format == '%')
						{
								c += printe(&all);
						}
						else if (*format == 's')
						{
								c += prints(arg, &all);
								// do S
						}
						else if (*format == 'c')
						{
								c += printc(arg, &all);
						}
						else if (*format == 'i' || *format == 'd')
						{
								c += printi(arg, &all);
						}
						else if (*format == 'x')
						{
								printx(arg, &all, 0);
						}
						else if (*format == 'X')
						{
								printx(arg, &all, 1);
						}
						else if (*format == 'p')
						{
							//	printp(arg, &all, 0);
						}
						else
						{
								ft_putendl_fd("format error", 2);
								return (p);
						}
				}
				else
				{
						ft_putchar(*format);
						p++;
				}
				format++;
		}
		return (p);
}

int		ft_printf(const char *format, ...)
{
		int	ret;
		va_list	arg;

		va_start(arg, format);
		ret = parse(arg, format);
		va_end(arg);
		return (ret);
}
