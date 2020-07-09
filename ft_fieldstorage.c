/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fieldstorage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_fieldstorage(va_list *p_ap,const char *fmt,int *fmt_inc, struct fields *f)
{
    /*
     * Eh preciso corrigit fmt na ft_printf 
     * pq aqui caminha-se nela
     *
     */
    int fmt_acc;
    *fmt_inc = 0; //fmt n foi incrementada ainda
    if(ft_fillflags(fmt,fmt_inc,f) == -1) //-------------chama 1 funcao
        return(-1);
    fmt += *fmt_inc; //corrige referencia
    fmt_acc = *fmt_inc;//acumula p devolver p printf
    *fmt_inc = 0;
    ft_fillwidth(p_ap,fmt,fmt_inc,f);         //---------------chama 2 funcao   
    fmt += *fmt_inc; //corrige referencia
    fmt_acc += *fmt_inc;//acumula p devolver p printf
    if (f->point)
    {
        *fmt_inc = 0;
        if(ft_fillprecision(p_ap, fmt, fmt_inc, f) == -1) //----- + 1 funcao
            return (-1);
        fmt += *fmt_inc; //corrige referencia
        fmt_acc += *fmt_inc;//acumula p devolver p printf
    }
    *fmt_inc = 0;
    ft_fillspecifier(fmt, fmt_inc, f);   //------------- + 1 funcao
    fmt += *fmt_inc; //corrige referencia
    fmt_acc += *fmt_inc;//acumula p devolver p printf
    *fmt_inc = fmt_acc; 
    return (0);
}
