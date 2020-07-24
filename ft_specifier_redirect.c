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

void	ft_specifier_redirect(va_list *p_ap, char sp, int *p, t_fields *f)
{
	if (sp == 'd' || sp == 'i')
		ft_printint(p_ap, 1, p, f);
	else if (sp == 'u')
		ft_printint(p_ap, 0, p, f);
	else if (sp == 'c')
		ft_printchar(p_ap, p, f);
	else if (sp == 's')
		ft_printstr(p_ap, p, f);
	else if (sp == 'x')
		ft_printhex(p_ap, 0, p, f);
	else if (sp == 'X')
		ft_printhex(p_ap, 1, p, f);
	else if (sp == 'p')
		ft_printpointer(p_ap, p, f);
	else if (sp == '%')
		ft_printpercent(p, f);
}
