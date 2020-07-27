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

void	ft_printchar(t_fields *f)
{
	char	c;
	int		space;

	space = f->width - 1;
	c = (char)va_arg(f->ap, int);
	if (f->flagminus)
	{
		ft_putchar(c, &(f->printed));
		ft_printspacezero(1, space, &(f->printed));
	}
	else
	{
		ft_printspacezero(1, space, &(f->printed));
		ft_putchar(c, &(f->printed));
	}
}
