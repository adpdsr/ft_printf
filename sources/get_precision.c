/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:53:54 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/10 14:54:41 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_precision(char **format, t_all *all)
{
	if (**format == '.')
	{
		(*format)++;
		all->precised = 1;
		while (ft_isdigit(**format))
		{
			all->precision = all->precision * 10 + ((**format) - '0');
			(*format)++;
		}
	}
	else
		all->precised = 0;
	return (*format);
}
