//
// HEADER
//

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

/*#include "../libft/libft.h"*/
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <wchar.h>

#define CHAR 1
#define LONG_LONG_INT 2
#define SHORT_INT 3
#define LONG_INT 4
#define INTMAXT 5
#define SIZET 6


typedef struct	s_all
{
	int	prefix;
	int	zero_pad;
	int	right_pad;
	int	blank_sign;
	int	always_sign;

	int	width;

	int	precision;
	int	precised;

	int	length;
	int	cnt;

}		t_all;

/* LIBFT */

void	ft_bzero(void *str, size_t n);
int	ft_isdigit(int c);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlen(char const *str);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

/* PRINTF */

typedef void	(* t_type)(va_list, t_all *, char);
t_type		get_type(char c);

void	printp(va_list arg, t_all *all, char c);
void	printe(va_list arg, t_all *all, char c);
void	printu(va_list arg, t_all *all, char c);
void	printx(va_list arg, t_all *all, char c);
void	printo(va_list arg, t_all *all, char c);
void	printi(va_list arg, t_all *all, char c);
void	printc(va_list arg, t_all *all, char c);
void	prints(va_list arg, t_all *all, char c);
void	printwc(va_list arg, t_all *all, char c);
void	printws(va_list arg, t_all *all, char c);

int		ft_printf(const char *format, ...);

char		*get_precision(char **format, t_all *all);
char		*get_length(char **format, t_all *all);
char		*get_width(char **format, t_all *all);
char		*get_flag(char **format, t_all *all);

void		ft_putnnbr(uintmax_t, int len);
void		ft_putnnbr_base(uintmax_t n, int len, unsigned int base, int flag);


#endif
