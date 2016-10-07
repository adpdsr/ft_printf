//
// HEADER
//

#include "../includes/ft_printf.h"

static int	is_length(char c)
{
		if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
				return (1);
		return (0);
}

char		*get_length(char **format, t_all *all)
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
