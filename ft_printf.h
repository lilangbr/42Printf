/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/08 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


struct fields{
    int     flagzero;
    int     flagminus;
    int     width;
    int     point;
    int     precision;
    char    specifier;
};


void    ft_putchar(char c, int *p);
void    ft_putstr(char *s, int *p, int qtt);
void    ft_putnbr(int n, int *p);
void    ft_putnbr_u(unsigned int n, int *p);
void    ft_putnbr_hex(size_t h, int capitalized, int *p);
void    ft_printspacezero(int type, int qtt, int *p); 
void    ft_printint(va_list *p_ap, int signal, int *p, struct fields *f);
void    ft_printpercent(int *p, struct fields *f);
void    ft_printhex(va_list *p_ap, int capitalized, int *p, struct fields *f);
void    ft_printpointer(va_list *p_ap, int *p, struct fields *f);
void    ft_printstr(va_list *p_ap, int *p, struct fields *f);
void    ft_printchar(va_list *p_ap, int *p, struct fields *f);
void    ft_strformat_init(struct fields *f);
int     ft_getnumber(const char *fmt, int *fmt_inc);
int     ft_fieldstorage(va_list *p_ap, const char *fmt,int *fmt_inc, struct fields *f);
void    ft_fillflags(const char *fmt, int *fmt_inc, struct fields *f);
void    ft_fillwidth(va_list *p_ap, const char *fmt,int *fmt_inc,struct fields *f);
int     ft_fillprecision(va_list *p_ap, const char *fmt, int *fmt_inc, struct fields *f);
int     ft_fillspecifier(const char *fmt, int *fmt_inc, struct fields *f);
void    ft_specifier_redirect(va_list *p_ap, char sp, int *p, struct fields *f);
int     ft_printf(const char *fmt, ...);


#endif

