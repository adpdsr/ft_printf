/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:52:30 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 15:18:24 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_width(char **format, t_all *all)
{
	if (ft_isdigit(**format) && **format != '0')
	{
		all->widthed = 1;
		while (ft_isdigit(**format))
		{
			all->width = all->width * 10 + ((**format) - '0');
			(*format)++;
		}
	}
	return (*format);
}
