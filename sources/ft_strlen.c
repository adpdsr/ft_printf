//
// HEADER
//

#include "../includes/ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str && str[count] != '\0')
		count++;
	return (count);
}