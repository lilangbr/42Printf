/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hex(unsigned int h)
{
	int length;

	length = 1;
	while (h > 15)
	{
		h = h/16;
		length++;
	}
	return (length);
}
void		ft_printhex(va_list *p_ap, int capitalized, int *p, t_fields *f)
{
	unsigned int	h;
	int				h_len;
	int				space;
	int				zero;

	h = va_arg(*p_ap, unsigned int);
	h_len = len_hex(h);
	if (!f->precision && !h && f->point)
		h_len = 0;
    if (f->point && (f->precision >= 0))
	{
		zero = f->precision - h_len;
		if (zero > 0)
			space = f->width - f->precision;
		else
			space = f->width - h_len;
		if(!(f->flagminus))
		{
			ft_printspacezero( 1, space, p);
			if (zero > 0)
				ft_printspacezero( 0, zero, p);
			if (h_len)
				ft_putnbr_hex(h, capitalized, p);
		}
		else
		{
			if(zero > 0)
				ft_printspacezero( 0, zero, p);
			if(h_len)
				ft_putnbr_hex(h, capitalized, p);
			ft_printspacezero( 1, space, p);
		}
	}
	else
	{
		space = f->width - h_len;
		zero = space;
		if(f->flagzero && !f->flagminus)
		{
			ft_printspacezero(0, zero, p);
			if(h_len)
				ft_putnbr_hex(h, capitalized, p);
		}
		else
		{
			if(f->flagminus)
			{
				if(h_len)
					ft_putnbr_hex(h,capitalized, p);
				ft_printspacezero(1, space, p);
			}
			else
			{
				ft_printspacezero(1, space, p);
				if(h_len)
					ft_putnbr_hex(h,capitalized, p);
			}
		}
	}
}
