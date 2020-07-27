/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fieldstorage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 20:13:21 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fieldstorage(const char *fmt, t_fields *f)
{
	int fmt_acc;

	f->fmt_inc = 0;
	ft_fillflags(fmt, f);
	fmt += f->fmt_inc;
	fmt_acc = f->fmt_inc;
	f->fmt_inc = 0;
	ft_fillwidth(fmt, f);
	fmt += f->fmt_inc;
	fmt_acc += f->fmt_inc;
	if (f->point)
	{
		f->fmt_inc = 0;
		if (ft_fillprecision(fmt, f) == -1)
			return (-1);
		fmt += f->fmt_inc;
		fmt_acc += f->fmt_inc;
	}
	f->fmt_inc = 0;
	ft_fillspecifier(fmt, f);
	fmt += f->fmt_inc;
	fmt_acc += f->fmt_inc;
	f->fmt_inc = fmt_acc;
	return (0);
}
