/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/24 00:26:40 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cuthex(size_t number, int capitalized, int *p)
{
	size_t	div;
	int		mod;
	char	c;

	div = number / 16;
	mod = number % 16;
	if (div != 0)
		cuthex(div, capitalized, p);
	if (mod < 10)
		c = '0' + mod;
	else
	{
		if (capitalized)
			c = 'A' + (mod - 10);
		else
			c = 'a' + (mod - 10);
	}
	ft_putchar(c, p);
}

void		ft_putnbr_hex(size_t h, int capitalized, int *p)
{
	if (h != 0)
		cuthex(h, capitalized, p);
	else
		ft_putchar('0', p);
}
