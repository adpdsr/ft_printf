/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:51:55 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/13 16:31:35 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

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
	unsigned int	prefix;		// bool
	unsigned int	zero_pad;	// bool
	unsigned int	right_pad;	// bool
	unsigned int	blank_sign;	// bool
	unsigned int	always_sign;	// bool

	unsigned int	width;
	unsigned int	widthed;	// bool

	unsigned int	precision;
	unsigned int	precised;	// bool

	unsigned int	length;
	unsigned int	cnt;

}		t_all;

/* ft_printc.c */
void	ftp_putchar(t_all *all, char c);
void	ftp_putstr(t_all *all, char *s);
void	ftp_putnstr(t_all *all, char *s, int len);

/* ft_printwc.c */
void	ftp_putwchar(t_all *all, wchar_t c);
void	ftp_putwstr(t_all *all, wchar_t *s);
void	ftp_putnwstr(t_all *all, wchar_t *c, int len);

/* ft_nbrlen_base */
int		ft_nbrlen_base(uintmax_t n, char *base);

/* ft_putnnbr.c */
void	ft_putnnbr(uintmax_t, int len);

/* ft_putnnbr_base.c */
void	ft_putnnbr_base(uintmax_t n, int len, unsigned int base, int flag);

/* padding.c */
void    pad_width(t_all *all, unsigned int len, char c);

/* libft */
void	ft_bzero(void *str, size_t n);
int		ft_isdigit(int c);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(char c);
char	*ft_strchr(const char *str, int c);
void	ft_putstr(char const *s);
size_t	ft_strlen(char const *str);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

/* PRINTF */

intmax_t    cast_signed_int(va_list arg, t_all *all);
uintmax_t cast_unsigned_int(va_list arg, t_all *all);

typedef void	(* t_type)(va_list, t_all *, char);
t_type		get_type(char c);
int		is_type(char c);

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



#endif
