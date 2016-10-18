/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:47:24 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 15:31:11 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_strchr(const char *str, int c)
{
	char	*s;

	s = NULL;
	while (*str != '\0')
	{
		if (*str == c)
		{
			s = (char *)str;
			return (s);
		}
		str++;
	}
	return (NULL);
}
