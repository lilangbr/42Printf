/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 23:51:14 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_int(int a)
{
	int			length;
	long int	b;

	length = 1;
	b = a;
	if (a < 0)
		b = -b;
	while (b > 9)
	{
		b = b / 10;
		length++;
	}
	return (length);
}

static int		len_u(unsigned int u)
{
	int length;

	length = 1;
	while (u > 9)
	{
		u = u / 10;
		length++;
	}
	return (length);
}

static int		min(int n)
{
	if (n < 0)
		return (0);
	else
		return (n);
}

void			ft_printint(va_list *p_ap, int signal, int *p, t_fields *f)
{
	int d;
	int d_len;
	int neg;
	int space;
	int zero;

	neg = 0;
	if (!signal)
	{
		d = va_arg(*p_ap, unsigned int);
		d_len = len_u(d);
	}
	else
	{
		if ((d = va_arg(*p_ap, int)) < 0)
			neg = 1;
		d_len = len_int(d);
	}
	if (!f->precision && !d && f->point)
		d_len = 0;
	if (f->point && (f->precision >= 0))
	{
		zero = min(f->precision) - d_len;
		if (zero > 0)
			space = f->width - min(f->precision);
		else
			space = f->width - d_len;
		if (neg)
			space--;
		if (!(f->flagminus))
		{
			ft_printspacezero(1, space, p);
			if (neg)
				ft_putchar('-', p);
			if (zero > 0)
				ft_printspacezero(0, zero, p);
			if (d_len)
			{
				if (signal)
					ft_putnbr(d, p);
				else
					ft_putnbr_u(d, p);
			}
		}
		else
		{
			if (neg)
				ft_putchar('-', p);
			if (zero > 0)
				ft_printspacezero(0, zero, p);
			if (d_len)
			{
				if (signal)
					ft_putnbr(d, p);
				else
					ft_putnbr_u(d, p);
			}
			ft_printspacezero(1, space, p);
		}
	}
	else
	{
		if (neg)
			d_len++;
		space = f->width - d_len;
		zero = space;
		if (f->flagzero && !f->flagminus)
		{
			if (neg)
				ft_putchar('-', p);
			ft_printspacezero(0, zero, p);
			if (d_len)
			{
				if (signal)
					ft_putnbr(d, p);
				else
					ft_putnbr_u(d, p);
			}
		}
		else
		{
			if (f->flagminus)
			{
				if (neg)
					ft_putchar('-', p);
				if (d_len)
				{
					if (signal)
						ft_putnbr(d, p);
					else
						ft_putnbr_u(d, p);
				}
				ft_printspacezero(1, space, p);
			}
			else
			{
				ft_printspacezero(1, space, p);
				if (neg)
					ft_putchar('-', p);
				if (d_len)
				{
					if (signal)
						ft_putnbr(d, p);
					else
						ft_putnbr_u(d, p);
				}
			}
		}
	}
}
