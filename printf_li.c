/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_li.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*
 * ***************************************
 * to insert in libftprintf.h
 * ****************************************
 */
struct fields{
    int     flagzero;
    int     flagminus;
    int     width;
    int     point;
    int     precision;
    char    specifier;
};
static void     ft_putchar(char c, int *p);
static void     ft_putstr(char *s, int *p);
static void		cut(int number, int *p);
static void     ft_putnbr(int n, int *p);
static void     ft_int_print(va_list *p_ap, int *p);
static void     ft_str_print(va_list *p_ap, int *p);
static void     ft_char_print(va_list *p_ap, int *p);
static void     ft_strformat_init(struct fields *f);
static int      ft_fieldstorage(va_list *p_ap, const char *fmt,int *fmt_inc, struct fields *f);
static int      ft_fillflags(const char *fmt, int *fmt_inc, struct fields *f);
static void     ft_fillwidth(va_list *p_ap, const char *fmt,int *fmt_inc,struct fields *f);
static int      ft_fillprecision(va_list *p_ap, const char *fmt, int *fmt_inc, struct fields *f);
static int      ft_fillspecifier(const char *fmt, int *fmt_inc, struct fields *f);
static void     ft_specifier_redirect(va_list *p_ap, char sp, int *p);
int             ft_printf(const char *fmt, ...);

/*
 * ***************************************
 * aux functions
 * ****************************************
 */

static void     ft_putchar(char c, int *p)
{
    write(1, &c, 1);
    (*p)++;
}
static void     ft_putstr(char *s, int *p)
{
    if (s)
        while (*s)
            ft_putchar(*s++, p);
}
static void		cut(int number, int *p)
{
	int		div;
	int		mod;
	char	c;

	div = number / 10;
	mod = number % 10;
	if (div != 0)
		cut(div, p);
	c = '0' + mod;
	ft_putchar(c, p);
}

static void     ft_putnbr(int n, int *p)
{
	if (n != 0)
	{
		if (n < 0)
		{
			ft_putchar('-', p);
			if (n == -2147483648)
			{
				n = (-1) * (n / 10);
				cut(n, p);
				ft_putchar('8', p);
			}
			else
			{
				n = -n;
				cut(n, p);
			}
		}
		else
			cut(n, p);
	}
	else
		ft_putchar('0', p);
}
/* INT */
static void     ft_int_print(va_list *p_ap, int *p)
{ 
        int d;
        d = va_arg(*p_ap, int);
        ft_putnbr(d, p);
}
/* STRING */
static void     ft_str_print(va_list *p_ap, int *p)
{ 
        char *s;
        s = va_arg(*p_ap, char *);
        ft_putstr(s, p);
}
/* CHAR */
static void     ft_char_print(va_list *p_ap, int *p)
{ 
        char c;
        c = (char)va_arg(*p_ap, int);
        ft_putchar(c, p);
}
static void     ft_strformat_init(struct fields *f)
{
    f->flagminus = 0;
    f->flagzero = 0;
    f->width = 0;
    f->point = 0;
    f->precision = 0;
    f->specifier = '\0';

}
static int     ft_fillflags(const char *fmt, int *fmt_inc, struct fields *f)
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
        if(count_minus && count_zero)
            return(-1);
        fmt++;
        (*fmt_inc)++;
    }
    return (0);

}
static int      ft_getnumber(const char *fmt, int *fmt_inc)
{
    int number;

    number = 0;
    if(*fmt < 58 && *fmt > 47)
    {
        number = *fmt - 48;
        fmt++;
        (*fmt_inc)++;
        while(*fmt < 58 && *fmt > 47)
        {
            number = number*10 + (*fmt - 48);
            fmt++;
            (*fmt_inc)++;
        }
    }
            
    return (number);
}
static void     ft_fillwidth(va_list *p_ap, const char *fmt,int *fmt_inc,struct fields *f)
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
            (*fmt_inc)++;
        }
        else
        {
            f->width = ft_getnumber(fmt,fmt_inc);
            fmt = fmt + *fmt_inc;
        }
        if(*fmt == '.')
        {   
            f->point = 1;
            (*fmt_inc)++;
        }
        
    }
}
static int      ft_fillprecision(va_list *p_ap, const char *fmt, int *fmt_inc, struct fields *f)
{
    if(*fmt == '-')
        return (-1);
    else if (f->point)
    {
        if(*fmt == '*')
        {
            f->precision = va_arg(*p_ap, int);
            (*fmt_inc)++;
        }
        else
            f->precision = ft_getnumber(fmt,fmt_inc);
        return (0);
    }
    else
        return (0);
}
static int      ft_fillspecifier(const char *fmt, int *fmt_inc, struct fields *f)
{
    if( *fmt != 's' && *fmt != 'c' && *fmt != 'i' && *fmt != 'd')
        return (-1);
    else
    {
        f->specifier = *fmt;
        (*fmt_inc)++;
        return (0);
    }
}



static int     ft_fieldstorage(va_list *p_ap,const char *fmt,int *fmt_inc, struct fields *f)
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

/* CHOICE C S P D I U X */
static void     ft_specifier_redirect(va_list *p_ap, char sp, int *p)
{
    if(sp == 'd' || sp == 'i')
        ft_int_print(p_ap,p); 
    else if(sp == 'c')
        ft_char_print(p_ap,p); 
    else if(sp == 's')
        ft_str_print(p_ap,p); 
    /*
    */
}

/*
 * ***************************************
 * PRINTF
 * ****************************************
 */
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
                ft_specifier_redirect(&ap, strformat->specifier, &printed);
                fmt = fmt + fmt_inc;
            }
        }
    }
    va_end(ap);
    printf("\n\n----------------------\n");
    printf("\n->Last flag minus:--->%d\n", strformat->flagminus);
    printf("\n->Last flag zero:---->%d\n",strformat->flagzero);
    printf("\n->Last width:-------->%d\n",strformat->width);
    printf("\n->Last point:-------->%d\n",strformat->point);
    printf("\n->Last precision:---->%d\n", strformat->precision);
    printf("\n->Last specifier:---->%c\n", strformat->specifier);
    printf("\n\n----------------------\n");

    free(strformat);
    return (printed);
}
/*
 * ***************************************
 * MAIN
 * ****************************************
 */
int            main()
{
    int qtt;
    char c = 'C';
    int i = 42;

    printf("\n\nOriginal_Version\n");
    qtt = printf("Str:%s Char:%c Int d:%d Int i:%*.7i\n", "String",c,9066,14,i);
    printf("%d caracteres impressos\n", qtt);
    printf("\n\n----------------------\n");
    printf("\n\nDev_Version\n");
    qtt = ft_printf("Str:%s Char:%c Int d:%d Int i:%*.7i\n", "String",c,9066,14,i);
    printf("%d caracteres impressos\n", qtt);
    printf("\n\n----------------------\n");


    //qtt = ft_printf("\n*\n=======> %-00042.c\n", 145);
    //printf("\n%d caracteres impressos\n", qtt);
    //
    printf("\n\n\n|%000023.d|\n\n", 42);

    return (0);
}

