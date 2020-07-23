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

int		ft_fieldstorage(va_list *p_ap, const char *fmt,\
		int *fmt_inc, struct fields *f)
{
	int fmt_acc;

	*fmt_inc = 0;
	ft_fillflags(fmt, fmt_inc, f);
	fmt += *fmt_inc;
	fmt_acc = *fmt_inc;
	*fmt_inc = 0;
	ft_fillwidth(p_ap, fmt, fmt_inc, f);
	fmt += *fmt_inc;
	fmt_acc += *fmt_inc;
	if (f->point)
	{
		*fmt_inc = 0;
		if (ft_fillprecision(p_ap, fmt, fmt_inc, f) == -1)
			return (-1);
		fmt += *fmt_inc;
		fmt_acc += *fmt_inc;
	}
	*fmt_inc = 0;
	ft_fillspecifier(fmt, fmt_inc, f);
	fmt += *fmt_inc;
	fmt_acc += *fmt_inc;
	*fmt_inc = fmt_acc;
	return (0);
}
