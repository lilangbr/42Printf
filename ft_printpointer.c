/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_add(size_t add)
{
	int length;

	length = 1;
	while (add > 15)
	{
		add = add/16;
		length++;
	}
	return (length);
}
static int	min(int n)
{
	if (n < 0)
		return(0);
	else
		return(n);
}
void		ft_printpointer(va_list *p_ap, int *p, t_fields *f)
{
	int		add_len;
	size_t	add;
	int		space;
	int		zero;

	add = (size_t)va_arg(*p_ap, void *);
	add_len = len_add(add) + 2;
	if (!f->precision && !add && f->point)
		add_len = 2;
	if (f->point && (f->precision >= 0))
	{
		zero = min(f->precision) - len_add(add);
		if (zero > 0)
			space = f->width - f->precision;
		else
			space = f->width - add_len;
		if (!f->flagminus)
		{
			ft_printspacezero(1, space, p);
			ft_putstr("0x",p, 2);
			if (zero > 0)
				ft_printspacezero(0, zero, p);
			if (f->precision != 0)
				ft_putnbr_hex(add, 0, p);
		}
		else
		{
			ft_putstr("0x",p, 2);
			if (zero > 0)
				ft_printspacezero(0, zero, p);
			if (f->precision != 0)
				ft_putnbr_hex(add, 0, p);
			ft_printspacezero(1, space, p);
		}
	}
	else
	{
		space = f->width - add_len;
		zero = space;
		if (f->flagzero && !f->flagminus)
		{
			ft_printspacezero(0, space, p);
			ft_putstr("0x",p, 2);
			if (len_add(add))
				ft_putnbr_hex(add, 0, p);
		}
		else
		{
			if (f->flagminus)
			{
				ft_putstr("0x",p, 2);
				if (len_add(add))
					ft_putnbr_hex(add, 0, p);
				ft_printspacezero(1, space, p);
			}
			else
			{
				ft_printspacezero(1, space, p);
				ft_putstr("0x",p, 2);
				if (len_add(add))
					ft_putnbr_hex(add, 0, p);
			}
		}
	}
}
