//
// HEADER
//

#include "../includes/ft_printf.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
