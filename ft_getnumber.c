/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/23 20:29:12 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getnumber(const char *fmt, int *fmt_inc)
{
	int number;

	number = 0;
	if (*fmt < 58 && *fmt > 47)
	{
		number = *fmt - 48;
		fmt++;
		(*fmt_inc)++;
		while (*fmt < 58 && *fmt > 47)
		{
			number = number * 10 + (*fmt - 48);
			fmt++;
			(*fmt_inc)++;
		}
	}
	return (number);
}
