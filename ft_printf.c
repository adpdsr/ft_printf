//
// HEADER
//

#include "ft_printf.h"

static void	ft_putnbr_base(uintmax_t nbr, char *base, size_t baselen)
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

static char	*parse_flag(char **format, t_all *all)
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

static char *parse_width(char **format, t_all *all)
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

static char *parse_precision(char **format, t_all *all)
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

static void	ft_putnnbr_2(int n, int len, int ref)
{
	unsigned int nb;

	if (ref == len)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnnbr_2(nb / 10, len, ref++);
		ft_putchar((nb % 10) + '0');
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

static void	ft_putnnbr(int n, int len)
{
	ft_putnnbr_2(n, len, 0);
}

static int	prints(va_list arg, t_all *all)
{
	char	*str;

	// handle_width
	// si all->width > ft_strlen(str) ==> put space (all->width - len) times 
	if (all->precision)
		(str = va_arg(arg, char *)) ? ft_putnstr(str, all->precision) : ft_putstr("(null)");
	else
		(str = va_arg(arg, char *)) ? ft_putstr(str) : ft_putstr("(null)");
	return (ft_strlen(str));
}

static int	printc(va_list arg, t_all *all)
{
	while (all->width-- > 1)
		ft_putchar(' ');
	ft_putchar(va_arg(arg, int));
}

static int	printi(va_list arg, t_all *all)
{
	while (all->width-- > 2)
		ft_putchar(' ');
	if (all->precision)
		ft_putnnbr(va_arg(arg, int), all->precision);
	else
		ft_putnbr(va_arg(arg, int));
}
/*
static int	printi_base(va_list arg, t_all *all)
{
	
}*/

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
			format = parse_flag((char **)&format, &all);
			format = parse_width((char **)&format, &all);
			format = parse_precision((char **)&format, &all);
//			printf("\nall.prefix = [%d]\n", all.prefix);
//			printf("all.zero_pad = [%d]\n", all.zero_pad);
//			printf("all.right_pad = [%d]\n", all.right_pad);
//			printf("all.blank_sign = [%d]\n", all.blank_sign);
//			printf("all.always_sign = [%d]\n", all.always_sign);
//			printf("\nall.width = [%d]\n", all.width);
//			printf("all.precision = [%d]\n\n", all.precision);
//			printf("format = [%s]\n", format);

			if (*format == '%')
			{
				c += printc(arg, &all);
			}
			if (*format == 's')
			{
				c += prints(arg, &all);
			}
			else if (*format == 'c') // no precision
			{
				c += printc(arg, &all);
			}
			else if (*format == 'i' || *format == 'd')
			{
				c += printi(arg, &all);
			}
			else if (*format == 'x')
			{
				while (all.width-- > 2)
					ft_putchar(' ');
				ft_putnbr_base(va_arg(arg, int), "0123456789abcdef", 16); // putnnbr_base pour precision
			}
			else if (*format == 'X')
			{
				while (all.width-- > 2)
					ft_putchar(' ');
				ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF", 16); // putnnbr_base
			}
			else if (*format == 'p')
				ft_putnbr_base(va_arg(arg, int), "0123456789abcdef", 16); // putnnbr_base
			else
			{
				ft_putendl("format error"); // tmp
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

int			main(void)
{
	printf("printf    = [%s %d %c %i %x %X]\n", "test1", 2, '3', 4, 12, 13);
	ft_printf("ft_printf = [%s %d %c %i %x %X]\n\n", "test1", 2, '3', 4, 12, 13);
	
	printf("printf    = [%10s%3.1d %2c %2.1d %2.1x %4.1X]\n", "test1", 20, '3', 123451212, 50, 60);
	ft_printf("ft_printf = [%10s%3.1d %2c %2.1d %2.1x %4.1X]\n", "test1", 20, '3', 123451212, 50, 60);
	return (0);
}
