/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillspecifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 20:21:57 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillspecifier(const char *fmt, int *fmt_inc, t_fields *f)
{
	if (*fmt != 's' && *fmt != 'c' && *fmt != 'i'\
			&& *fmt != 'u' && *fmt != 'd' && *fmt != 'x'\
			&& *fmt != 'X' && *fmt != 'p' && *fmt != '%')
		return (-1);
	else
	{
		f->specifier = *fmt;
		(*fmt_inc)++;
		return (0);
	}
}
