/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      len_add(size_t add) 
{
    int length;
    
    length = 1;
    while (add > 15)
    {
        add = add/16;
        length++;
    }
    return (length);
}
void     ft_printpointer(va_list *p_ap, int *p, struct fields *f) 
{
    //Nao faz sentido precisao nem flag zero!
    //fazer fillspecifier rejeitar. Ela já é uma static int: Usar ela!
    int add_len;
    size_t add;
    int space;

    add = (size_t)va_arg(*p_ap, void *);//cplusplus.com/cstdio/printf/
    add_len = len_add(add) + 2;//'0x'
    space = f->width - add_len;
    if(f->flagminus)
    {
        ft_putstr("0x",p, 2);
        ft_putnbr_hex(add, 0, p);
        ft_printspacezero(1, space, p);
    }
    else
    {
        ft_printspacezero(1, space, p);
        ft_putstr("0x",p, 2);
        ft_putnbr_hex(add, 0, p);
    }
}
