//
// HEADER
//

#include <string.h>
#include "../includes/ft_printf.h"

void	ft_bzero(void *str, size_t n)
{
	if (n)
		ft_memset(str, 0, n);
}
