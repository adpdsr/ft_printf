/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:32:58 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/18 15:33:12 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		temp;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		temp = i;
		while (s1[i] && s2[j] && i < n && s1[i] == s2[j])
		{
			i++;
			j++;
		}
		if (!s2[j])
			return ((char*)&s1[temp]);
		else
			j = 0;
		i = temp + 1;
	}
	return (NULL);
}
