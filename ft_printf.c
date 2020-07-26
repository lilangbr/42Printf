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

static int	aux1(const char **fmt2, int *p)
{
	ft_putchar(**fmt2, p);
	(*fmt2)++;
	return (0);
}

static int	aux2(const char **fmt2, t_fields *f)
{
	ft_strformat_init(f);
	if (ft_fieldstorage(*fmt2, f) == -1)
	{
		free(f);
		return (-1);
	}
	ft_specifier_redirect(&(f->ap), f->specifier, &(f->printed), f);
	*fmt2 = *fmt2 + f->fmt_inc;
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	t_fields	*format;

	if (!fmt || !(format = (t_fields*)malloc(sizeof(t_fields))))
		return (-1);
	format->printed = 0;
	va_start(format->ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			aux1(&fmt, &(format->printed));
		else
		{
			fmt++;
			if (*fmt == '%')
				aux1(&fmt, &(format->printed));
			else if (aux2(&fmt, format) == -1)
				return (-1);
		}
	}
	va_end(format->ap);
	free(format);
	return (format->printed);
}
