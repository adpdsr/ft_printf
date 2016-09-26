//
// HEADER
//

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct		s_all
{
	int				prefix;
	int				zero_pad;
	int				right_pad;
	int				blank_sign;
	int				always_sign;
	
	unsigned int	width;
	int				precision;

}					t_all;

#endif
