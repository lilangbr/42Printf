/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 20:34:39 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(va_list *p_ap, int *p, struct fields *f)
{
	char	c;
	int		space;

	space = f->width - 1;
	c = (char)va_arg(*p_ap, int);
	if (f->flagminus)
	{
		ft_putchar(c, p);
		ft_printspacezero(1, space, p);
	}
	else
	{
		ft_printspacezero(1, space, p);
		ft_putchar(c, p);
	}
}
