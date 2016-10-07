//
// HEADER
//

#include "../includes/ft_printf.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*str;
	size_t	count;

	count = 0;
	str = malloc(size);
	if (str == NULL || size == 0)
		return (NULL);
	while (count != size)
	{
		str[count] = '\0';
		count++;
	}
	return (str);
}
