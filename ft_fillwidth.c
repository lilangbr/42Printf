/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 18:29:13 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void aux(int mode, t_fields *f, int *fmt_inc)
{
		if (mode == 1)
		{
			f->point = 1;
			f->width = 0;
			(*fmt_inc)++;
		}
		else if (mode == 2)
		{
			f->point = 1;
			(*fmt_inc)++;
		}
		else if (mode == 3)
		{
			f->flagminus = 1;
			f->flagzero = 0;
			f->width = -f->width;
		}

}

void	ft_fillwidth(va_list *p_ap, const char *fmt, int *fmt_inc, \
		t_fields *f)
{
	if (*fmt == '.')
		aux(1, f, fmt_inc);
	else
	{
		if (*fmt == '*')
		{
			f->width = va_arg(*p_ap, int);
			fmt++;
			(*fmt_inc)++;
		}
		else
		{
			f->width = ft_getnumber(fmt, fmt_inc);
			fmt = fmt + *fmt_inc;
		}
		if (*fmt == '.')
			aux(2, f, fmt_inc);
	}
	if (f->width < 0)
		aux(3, f, fmt_inc);
}
