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

typedef struct s_var
{
	int neg;
	int d_len;
	int signal;
	int space;
	int zero;
}				t_var;

static int	len_int(int a)
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

static int	len_u(unsigned int u)
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

static int	min(int n)
{
	if (n < 0)
		return (0);
	else
		return (n);
}

static void print_mod(int d_len, int signal, long int d, int *p)
{
	if (d_len)
	{
		if (signal)
			ft_putnbr(d, p);
		else
			ft_putnbr_u(d, p);
	}
}

static void aux_precision(t_fields *f, t_var *v, int *p, long int d)
{
	if ((v->zero = min(f->precision) - v->d_len) > 0)
		v->space = f->width - min(f->precision);
	else
		v->space = f->width - v->d_len;
	if (v->neg)
		v->space--;
	if (!(f->flagminus))
	{
		ft_printspacezero(1, v->space, p);
		if (v->neg)
			ft_putchar('-', p);
		ft_printspacezero(0, v->zero, p);
		print_mod(v->d_len, v->signal, d, p);
	}
	else
	{
		if (v->neg)
			ft_putchar('-', p);
		ft_printspacezero(0, v->zero, p);
		print_mod(v->d_len, v->signal, d, p);
		ft_printspacezero(1, v->space, p);
	}
}

static void	aux_noprecision(t_fields *f, t_var *v, int *p, long int d)
{
	if (v->neg)
		v->d_len++;
	v->space = f->width - v->d_len;
	v->zero = v->space;
	if (f->flagzero && !f->flagminus)
	{
		if (v->neg)
			ft_putchar('-', p);
		ft_printspacezero(0, v->zero, p);
		print_mod(v->d_len, v->signal, d, p);
	}
	else
	{
		if (f->flagminus)
		{
			if (v->neg)
				ft_putchar('-', p);
			print_mod(v->d_len, v->signal, d, p);
			ft_printspacezero(1, v->space, p);
		}
		else
		{
			ft_printspacezero(1, v->space, p);
			if (v->neg)
				ft_putchar('-', p);
			print_mod(v->d_len, v->signal, d, p);
		}
	}
}

void		ft_printint(va_list *p_ap, int signal, int *p, t_fields *f)
{
	int		d;
	t_var	*var;

	if (!(var = (t_var*)malloc(sizeof(t_var))))
		return;
	var->neg = 0;
	var->signal = signal;
	if (!signal)
	{
		d = va_arg(*p_ap, unsigned int);
		var->d_len = len_u(d);
	}
	else
	{
		if ((d = va_arg(*p_ap, int)) < 0)
			var->neg = 1;
		var->d_len = len_int(d);
	}
	if (!f->precision && !d && f->point)
		var->d_len = 0;
	if (f->point && (f->precision >= 0))
		aux_precision(f, var, p, d);
	else
		aux_noprecision(f, var, p, d);
	free(var);
}
