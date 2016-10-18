/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:51:55 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 18:02:39 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>

# define CHAR			1
# define LONG_LONG_INT	2
# define SHORT_INT		3
# define LONG_INT		4
# define INTMAXT		5
# define SIZET			6

typedef struct		s_all
{
	unsigned int	prefix;
	unsigned int	zero_pad;
	unsigned int	right_pad;
	unsigned int	blank_sign;
	unsigned int	always_sign;

	unsigned int	width;
	unsigned int	widthed;

	unsigned int	precision;
	unsigned int	precised;

	unsigned int	length;
	unsigned int	cnt;

}					t_all;

void				ftp_putchar(t_all *all, char c);
void				ftp_putstr(t_all *all, char *s);
void				ftp_putnstr(t_all *all, char *s, int len);

void				ftp_putwchar(t_all *all, wchar_t c);
void				ftp_putwstr(t_all *all, wchar_t *s);
void				ftp_putnwstr(t_all *all, wchar_t *c, int len);

int					ft_nbrlen_base(uintmax_t n, char *base);

void				ft_putnnbr(uintmax_t nb, int len);

void				ft_putnnbr_base(uintmax_t n, int len,\
					unsigned int base, int flag);

char				*get_prefix(t_all *all, char c);
void				put_prefix(t_all *all, char *prefix, int len, int flag);

void				pad_width2(t_all *all, char *prefix,\
					unsigned int len, char c);
void				pad_precision(t_all *all, unsigned int len);

void				pad_width(t_all *all, unsigned int len, char c);

void				ft_bzero(void *str, size_t n);
int					ft_isdigit(int c);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
char				*ft_strchr(const char *str, int c);
void				ft_putstr(char const *s);
size_t				ft_strlen(char const *str);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);

int					ft_nwstrlen(wchar_t *s, int n);
size_t				ft_nstrlen(char *s, unsigned int n);
size_t				ft_wstrlen(wchar_t *s);

intmax_t			cast_signed_int(va_list arg, t_all *all);
uintmax_t			cast_unsigned_int(va_list arg, t_all *all);

typedef	void		(*t_type)(va_list, t_all *, char);
t_type				get_type(char c);
int					is_type(char c);

void				ftp_putnchar(t_all *all, char c, int n);

void				printp(va_list arg, t_all *all, char c);
void				printe(va_list arg, t_all *all, char c);
void				printu(va_list arg, t_all *all, char c);
void				printx(va_list arg, t_all *all, char c);
void				printo(va_list arg, t_all *all, char c);
void				printi(va_list arg, t_all *all, char c);
void				printc(va_list arg, t_all *all, char c);
void				prints(va_list arg, t_all *all, char c);
void				printwc(va_list arg, t_all *all, char c);
void				printws(va_list arg, t_all *all, char c);

int					ft_printf(const char *format, ...);

char				*get_precision(char **format, t_all *all);
char				*get_length(char **format, t_all *all);
char				*get_width(char **format, t_all *all);
char				*get_flag(char **format, t_all *all);

#endif
