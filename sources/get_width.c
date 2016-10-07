//
// HEADER
//

#include "../includes/ft_printf.h"

char	*get_width(char **format, t_all *all)
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
