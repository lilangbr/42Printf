/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 23:29:01 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	aux(int mode, const char **fmt2, int *p, t_fields *f, int *fmt_inc, va_list *p_ap)
{
	if (mode == 1)
	{
		ft_putchar(**fmt2, p);
		(*fmt2)++;
		return (0);
	}
	else if (mode == 2)
	{
		ft_strformat_init(f);
		if (ft_fieldstorage(p_ap, *fmt2, fmt_inc, f) == -1)
		{
			free(f);
			return (-1);
		}
		ft_specifier_redirect(p_ap, f->specifier, p, f);
		*fmt2 = *fmt2 + *fmt_inc;
		return (0);
	}
	return (0);
}
int			ft_printf(const char *fmt, ...)
{
	int			printed;
	int			fmt_inc;
	va_list		ap;
	t_fields	*strformat;

	if (!fmt || !(strformat = (t_fields*)malloc(sizeof(t_fields))))
		return (-1);
	printed = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			aux(1, &fmt, &printed, strformat, &fmt_inc, &ap);
		else
		{
			fmt++;
			if (*fmt == '%')
				aux(1, &fmt, &printed, strformat, &fmt_inc, &ap);
			else if (aux(2, &fmt, &printed, strformat, &fmt_inc, &ap) == -1)
				return(-1);
		}
	}
	va_end(ap);
	free(strformat);
	return (printed);
}
