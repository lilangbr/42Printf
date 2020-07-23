/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillspecifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int      ft_fillspecifier(const char *fmt, int *fmt_inc, struct fields *f)
{
    if( *fmt != 's' && *fmt != 'c' && *fmt != 'i' && *fmt != 'u' && *fmt != 'd' && *fmt != 'x' && *fmt != 'X' && *fmt != 'p' && *fmt != '%')
        return (-1);
    else
    {
        f->specifier = *fmt;
        //
        //(if specifier = p e existe flah 0 ou precisao: return -1, etc)
        //
        //AQUI VAI CONTROLE DE FLAGS ----erros de input
        //
        //
        (*fmt_inc)++;
        return (0);
    }
}
