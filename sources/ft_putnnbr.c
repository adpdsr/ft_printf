//
// HEADER
//

#include "../includes/ft_printf.h"

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

void	ft_putnnbr(uintmax_t n, int len)
{
		ft_putnnbr_2(n, len, 0);
}
