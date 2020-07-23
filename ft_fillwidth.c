/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     ft_fillwidth(va_list *p_ap, const char *fmt,int *fmt_inc,struct fields *f)
{
    if(*fmt == '.')
    {
        f->point = 1;
        f->width = 0;
        fmt++;
        (*fmt_inc)++;
    }
    else
    {
        if (*fmt == '*')
        {
            f->width = va_arg(*p_ap, int);
            fmt++;
//            printf("\n***********width = %d\n", f->width);
//            printf("\n***********fmt = %c\n", *fmt);
            (*fmt_inc)++;
        }
        else
        {
            f->width = ft_getnumber(fmt,fmt_inc);
            fmt = fmt + *fmt_inc;
//            printf("\n***********width = %d\n", f->width);
//            printf("\n-----------fmt = %c\n", *fmt);
        }
        if(*fmt == '.')
        {   
            f->point = 1;
            (*fmt_inc)++;
        }
        
    }
    if(f->width < 0) //**************************************16julho
    {
        f->flagminus = 1;
        f->flagzero = 0;
        f->width = - f->width;
    }
}
