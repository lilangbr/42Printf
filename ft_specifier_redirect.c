/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/24 00:31:51 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_redirect(char sp, t_fields *f)
{
	if (sp == 'd' || sp == 'i')
		ft_printint(1, f);
	else if (sp == 'u')
		ft_printint(0, f);
	else if (sp == 'c')
		ft_printchar(f);
	else if (sp == 's')
		ft_printstr(f);
	else if (sp == 'x')
		ft_printhex(0, f);
	else if (sp == 'X')
		ft_printhex(1, f);
	else if (sp == 'p')
		ft_printpointer(f);
	else if (sp == '%')
		ft_printpercent(f);
}
