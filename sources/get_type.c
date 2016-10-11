/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 20:38:36 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/11 20:38:38 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_ptr_types(t_type *type)
{
	type['%'] = &printe;
	type['s'] = &prints;
	type['c'] = &printc;
	type['i'] = &printi;
	type['d'] = &printi;
	type['D'] = &printi;
	type['x'] = &printx;
	type['X'] = &printx;
	type['p'] = &printp;
	type['o'] = &printo;
	type['O'] = &printo;
	type['u'] = &printu;
	type['U'] = &printu;
	type['S'] = &printws;
	type['C'] = &printwc;
}

t_type		get_type(char c)
{
	t_type		*type;

	type = ft_memalloc(sizeof(t_type) * 256);
	if (type)
		init_ptr_types(type);
	return (type[(int)c]);
}
