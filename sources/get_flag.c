//
// HEADER
//

#include "../includes/ft_printf.h"

static int	is_flag(char c)
{
		if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
				return (1);
		return (0);
}

char		*get_flag(char **format, t_all *all)
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
