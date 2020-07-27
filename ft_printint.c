/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/26 23:39:04 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_mod(int d_len, int signal, long int d, int *p)
{
	if (d_len)
	{
		if (signal)
			ft_putnbr(d, p);
		else
			ft_putnbr_u(d, p);
	}
}

static void	aux_precision(t_fields *f, t_var *v, long int d)
{
	if ((v->zero = ft_min(f->precision) - v->d_len) > 0)
		v->space = f->width - ft_min(f->precision);
	else
		v->space = f->width - v->d_len;
	if (v->neg)
		v->space--;
	if (!(f->flagminus))
	{
		ft_printspacezero(1, v->space, &(f->printed));
		if (v->neg)
			ft_putchar('-', &(f->printed));
		ft_printspacezero(0, v->zero, &(f->printed));
		print_mod(v->d_len, v->signal, d, &(f->printed));
	}
	else
	{
		if (v->neg)
			ft_putchar('-', &(f->printed));
		ft_printspacezero(0, v->zero, &(f->printed));
		print_mod(v->d_len, v->signal, d, &(f->printed));
		ft_printspacezero(1, v->space, &(f->printed));
	}
}

static void	aux_noprecision(t_fields *f, t_var *v, long int d)
{
	if (v->neg)
		v->d_len++;
	v->space = f->width - v->d_len;
	v->zero = v->space;
	if (f->flagzero && !f->flagminus)
	{
		if (v->neg)
			ft_putchar('-', &(f->printed));
		ft_printspacezero(0, v->zero, &(f->printed));
		print_mod(v->d_len, v->signal, d, &(f->printed));
	}
	else
	{
		if (!f->flagminus)
			ft_printspacezero(1, v->space, &(f->printed));
		if (v->neg)
			ft_putchar('-', &(f->printed));
		print_mod(v->d_len, v->signal, d, &(f->printed));
		if (f->flagminus)
			ft_printspacezero(1, v->space, &(f->printed));
	}
}

void		ft_printint(int signal, t_fields *f)
{
	int		d;
	t_var	*var;

	if (!(var = (t_var*)malloc(sizeof(t_var))))
		return ;
	var->neg = 0;
	if (!(var->signal = signal))
	{
		d = va_arg(f->ap, unsigned int);
		var->d_len = ft_len_u(d);
	}
	else
	{
		if ((d = va_arg(f->ap, int)) < 0)
			var->neg = 1;
		var->d_len = ft_len_int(d);
	}
	if (!f->precision && !d && f->point)
		var->d_len = 0;
	if (f->point && (f->precision >= 0))
		aux_precision(f, var, d);
	else
		aux_noprecision(f, var, d);
	free(var);
}
