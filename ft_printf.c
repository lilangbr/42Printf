/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/08 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int             ft_printf(const char *fmt, ...)
{
    int printed;
    int fmt_inc;
    va_list ap;
    struct fields *strformat;
    
    if(!fmt)
        return(-1);
    printed = 0;
    strformat = (struct fields*)malloc(sizeof(struct fields));
    va_start(ap, fmt);
    while (*fmt)
    {
        if(*fmt != '%')
        {
            ft_putchar(*fmt, &printed);
            fmt++;
        }
        else
        {
            fmt++;
            if(*fmt == '%')
            {
                ft_putchar(*fmt, &printed);
                fmt++;
            }
            else
            {
                ft_strformat_init(strformat);
                if(ft_fieldstorage(&ap, fmt,&fmt_inc,strformat) == -1)
                {
                    free(strformat);
                    return (-1);
                }
                ft_specifier_redirect(&ap, strformat->specifier, &printed, strformat);
                fmt = fmt + fmt_inc;

              /* TO DEBUG FLAG STORAGE
                *
                printf("\nminus( %d ) ", strformat->flagminus);
                printf("zero( %d ) ",strformat->flagzero);
                printf("width( %d ) ",strformat->width);
                printf("point( %d ) ",strformat->point);
                printf("precision( %d ) ", strformat->precision);
                printf("specifier( %c )\n\n", strformat->specifier);
                *
                */
            }
        }
    }
    va_end(ap);

    free(strformat);
    return (printed);
}

