/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/26 22:36:21 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_fields{
	va_list		ap;
	int			printed;
	int			fmt_inc;
	int			flagzero;
	int			flagminus;
	int			width;
	int			point;
	int			precision;
	char		specifier;
}				t_fields;

typedef struct	s_var
{
	int			neg;
	int			d_len;
	int			signal;
	int			space;
	int			zero;
}				t_var;

void			ft_putchar(char c, int *p);
void			ft_putstr(char *s, int *p, int qtt);
void			ft_putnbr(int n, int *p);
void			ft_putnbr_u(unsigned int n, int *p);
void			ft_putnbr_hex(size_t h, int capitalized, int *p);
void			ft_printspacezero(int type, int qtt, int *p);
void			ft_printint(int signal, t_fields *f);
int				ft_min(int n);
int				ft_len_u(unsigned int u);
int				ft_len_int(int a);
void			ft_printpercent(t_fields *f);
void			ft_printhex(int capitalized, t_fields *f);
void			ft_printpointer(t_fields *f);
int				ft_len_add(size_t add);
void			ft_printstr(t_fields *f);
void			ft_printchar(t_fields *f);
void			ft_strformat_init(t_fields *f);
int				ft_getnumber(const char *fmt, int *fmt_inc);
int				ft_fieldstorage(const char *fmt, t_fields *f);
void			ft_fillflags(const char *fmt, t_fields *f);
void			ft_fillwidth(const char *fmt, t_fields *f);
int				ft_fillprecision(const char *fmt, t_fields *f);
int				ft_fillspecifier(const char *fmt, t_fields *f);
void			ft_specifier_redirect(char sp, t_fields *f);
int				ft_printf(const char *fmt, ...);

#endif
