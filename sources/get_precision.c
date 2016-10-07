//
// HEADER
//

#include "../includes/ft_printf.h"

char	*get_precision(char **format, t_all *all)
{
	if (**format == '.')
	{
		(*format)++;
		// gestion erreur ?
		all->precised = 1;
		while (ft_isdigit(**format))
		{
			all->precision = all->precision * 10 + ((**format) - '0');
			(*format)++;
		}
	}
	else
		all->precised = 0;
	return (*format);
}
