//
// HEADER
//

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#define CHAR 1
#define LONG_LONG_INT 2
#define SHORT_INT 3
#define LONG_INT 4
#define INTMAXT 5
#define SIZET 6

typedef struct				s_all
{
	int				prefix;
	int				zero_pad;
	int				right_pad;
	int				blank_sign;
	int				always_sign;
	
	int				width;
	int				precision;
	int				length;

}					t_all;

int	ft_printf(const char *format, ...);

#endif
