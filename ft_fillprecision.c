/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillprecision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 20:17:18 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillprecision(const char *fmt, t_fields *f)
{
	if (*fmt == '-')
		return (-1);
	else if (f->point)
	{
		if (*fmt == '*')
		{
			f->precision = va_arg(f->ap, int);
			(f->fmt_inc)++;
		}
		else
			f->precision = ft_getnumber(fmt, &(f->fmt_inc));
		return (0);
	}
	else
		return (0);
}
