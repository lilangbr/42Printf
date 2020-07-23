/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillprecision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 18:19:32 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillprecision(va_list *p_ap, const char *fmt, int *fmt_inc, struct fields *f)
{
	if (*fmt == '-')
		return (-1);
	else if (f->point)
	{
		if (*fmt == '*')
		{
			f->precision = va_arg(*p_ap, int);
			(*fmt_inc)++;
		}
		else
			f->precision = ft_getnumber(fmt, fmt_inc);
		return (0);
	}
	else
		return (0);
}
