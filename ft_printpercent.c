/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 23:54:15 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printpercent(int *p, t_fields *f)
{
	int space;
	int zero;

	space = f->width - 1;
	zero = space;
	if (f->flagzero && !f->flagminus)
	{
		ft_printspacezero(0, zero, p);
		ft_putchar('%', p);
	}
	else
	{
		if (f->flagminus)
		{
			ft_putchar('%', p);
			ft_printspacezero(1, space, p);
		}
		else
		{
			ft_printspacezero(1, space, p);
			ft_putchar('%', p);
		}
	}
}
