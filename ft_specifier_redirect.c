/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     ft_specifier_redirect(va_list *p_ap, char sp, int *p, struct fields *f)
{
    if(sp == 'd' || sp == 'i') //OK
        ft_printint(p_ap, 1, p,f); 
    if(sp == 'u') //OK
        ft_printint(p_ap, 0, p,f); 
    else if(sp == 'c') //OK
        ft_printchar(p_ap,p, f); 
    else if(sp == 's') //OK
        ft_printstr(p_ap,p, f); 
    else if(sp == 'x') //OK
        ft_printhex(p_ap, 0, p, f);
    else if(sp == 'X') //OK
        ft_printhex(p_ap, 1, p, f);
    else if(sp == 'p') //OK
        ft_printpointer(p_ap, p, f);
    else if(sp == '%')
        ft_printpercent(p, f);
}

