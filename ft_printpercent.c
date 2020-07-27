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

void	ft_printpercent(t_fields *f)
{
	int space;
	int zero;

	space = f->width - 1;
	zero = space;
	if (f->flagzero && !f->flagminus)
	{
		ft_printspacezero(0, zero, &(f->printed));
		ft_putchar('%', &(f->printed));
	}
	else
	{
		if (f->flagminus)
		{
			ft_putchar('%', &(f->printed));
			ft_printspacezero(1, space, &(f->printed));
		}
		else
		{
			ft_printspacezero(1, space, &(f->printed));
			ft_putchar('%', &(f->printed));
		}
	}
}
