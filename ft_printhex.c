/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/27 00:56:33 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	aux_precision(t_fields *f, int h_len, int cap, unsigned int h)
{
	int space;
	int zero;

	zero = f->precision - h_len;
	if (zero > 0)
		space = f->width - f->precision;
	else
		space = f->width - h_len;
	if (!(f->flagminus))
		ft_printspacezero(1, space, &(f->printed));
	if (zero > 0)
		ft_printspacezero(0, zero, &(f->printed));
	if (h_len)
		ft_putnbr_hex(h, cap, &(f->printed));
	if (f->flagminus)
		ft_printspacezero(1, space, &(f->printed));
}

static void	aux_noprecision(t_fields *f, int h_len, int cap, unsigned int h)
{
	int space;

	space = f->width - h_len;
	if (f->flagzero && !f->flagminus)
	{
		ft_printspacezero(0, space, &(f->printed));
		if (h_len)
			ft_putnbr_hex(h, cap, &(f->printed));
	}
	else
	{
		if (!f->flagminus)
			ft_printspacezero(1, space, &(f->printed));
		if (h_len)
			ft_putnbr_hex(h, cap, &(f->printed));
		if (f->flagminus)
			ft_printspacezero(1, space, &(f->printed));
	}
}

void		ft_printhex(int capitalized, t_fields *f)
{
	unsigned int	h;
	int				h_len;

	h = va_arg(f->ap, unsigned int);
	h_len = ft_len_hex(h);
	if (!f->precision && !h && f->point)
		h_len = 0;
	if (f->point && (f->precision >= 0))
		aux_precision(f, h_len, capitalized, h);
	else
		aux_noprecision(f, h_len, capitalized, h);
}
