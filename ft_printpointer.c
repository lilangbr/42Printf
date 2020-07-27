/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/27 00:50:05 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	aux_noprecision(t_fields *f, size_t add, int add_len)
{
	int space;

	space = f->width - add_len;
	if (f->flagzero && !f->flagminus)
	{
		ft_printspacezero(0, space, &(f->printed));
		ft_putstr("0x", &(f->printed), 2);
		if (ft_len_add(add))
			ft_putnbr_hex(add, 0, &(f->printed));
	}
	else
	{
		if (!f->flagminus)
			ft_printspacezero(1, space, &(f->printed));
		ft_putstr("0x", &(f->printed), 2);
		if (ft_len_add(add))
			ft_putnbr_hex(add, 0, &(f->printed));
		if (f->flagminus)
			ft_printspacezero(1, space, &(f->printed));
	}
}

static void	aux_precision(t_fields *f, size_t add, int add_len)
{
	int zero;
	int space;

	zero = ft_min(f->precision) - ft_len_add(add);
	if (zero > 0)
		space = f->width - f->precision;
	else
		space = f->width - add_len;
	if (!f->flagminus)
		ft_printspacezero(1, space, &(f->printed));
	ft_putstr("0x", &(f->printed), 2);
	if (zero > 0)
		ft_printspacezero(0, zero, &(f->printed));
	if (f->precision != 0)
		ft_putnbr_hex(add, 0, &(f->printed));
	if (f->flagminus)
		ft_printspacezero(1, space, &(f->printed));
}

void		ft_printpointer(t_fields *f)
{
	int		add_len;
	size_t	add;

	add = (size_t)va_arg(f->ap, void *);
	add_len = ft_len_add(add) + 2;
	if (!f->precision && !add && f->point)
		add_len = 2;
	if (f->point && (f->precision >= 0))
		aux_precision(f, add, add_len);
	else
		aux_noprecision(f, add, add_len);
}
