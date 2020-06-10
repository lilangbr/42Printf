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
static void     ft_putchar(char c, int *p);
static void     ft_putstr(char *s, int *p);
static void		cut(int number, int *p);
static void     ft_putnbr(int n, int *p);
static void     ft_int_print(va_list *p_ap, int *p);
static void     ft_str_print(va_list *p_ap, int *p);
static void     ft_char_print(va_list *p_ap, int *p);
static void     ft_specifier_redirect(va_list *p_ap, char sp, int *p);
int             ft_printf(const char *fmt, ...);
struct fields{
    char specifier;
};

/*
 * ***************************************
 * aux functions
 * ****************************************
 */
//static void     ft_strformat_init(strformat)
//{
//    strformat = (struct fields *)malloc(1*sizeof(char));
//    strformat->specifier = 0;
//}
                //ft_fieldstorage(fmt,strformat,printed);
/*
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
    int *printed;
    int count;
    va_list ap;
    //struct fields *strformat;
    struct fields strformat;

    if(!fmt)
        return(-1);
    count = 0;
    printed = &count;
    va_start(ap, fmt);
    while (*fmt)
    {
        if(*fmt != '%')
        {
            ft_putchar(*fmt, printed);
            fmt++;
        }
        else
        {
            fmt++;
            if(*fmt == '%')
            {
                ft_putchar(*fmt, printed);
                fmt++;
            }
            else
            {
                strformat.specifier = *fmt;
                //printf("%c\n", strformat.specifier);
                
                //ft_strformat_init(strformat);
                //ft_fieldstorage(fmt,strformat,printed);
                ft_specifier_redirect(&ap, strformat.specifier, printed);
                       
            //ft_putstr((char *)va_arg(ap, char *), printed);
                fmt++;
            }
        }
    }
    va_end(ap);
    return (*printed);
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

    printf("Dev_Version\n");
    qtt = ft_printf("Ola%s que tal? %s %c, de coder! Sobrenome %d!!!\n", ", Matheus", "Curtiu?", c, i);
    printf("%d caracteres impressos\n", qtt);
    printf("Original_Version\n");
    qtt = printf("Ola%s que tal? %s %c, de coder! Sobrenome %d!!!\n", ", Matheus", "Curtiu?", c, i);
    printf("%d caracteres impressos\n", qtt);




    return (0);
}

