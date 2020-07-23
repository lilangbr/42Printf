/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     ft_fillflags(const char *fmt, int *fmt_inc, struct fields *f)
{
    int count_minus;
    int count_zero;
    count_minus = 0;
    count_zero = 0;

    while(*fmt == '-' || *fmt == '0')
    {
        if(*fmt == '-' && count_minus == 0)
        {
            f->flagminus = 1;
            count_minus++;
        }
        if(*fmt == '0' && count_zero == 0)
        {
            f->flagzero = 1;
            count_zero++;
        }
        fmt++;
        (*fmt_inc)++;
    }
}
