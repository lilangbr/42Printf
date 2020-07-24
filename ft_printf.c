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

int			ft_printf(const char *fmt, ...)
{
	int			printed;
	int			fmt_inc;
	va_list		ap;
	t_fields	*strformat;

	if (!fmt)
		return(-1);
	printed = 0;
	strformat = (t_fields*)malloc(sizeof(t_fields));
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
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
			}
		}
	}
	va_end(ap);
	free(strformat);
	return (printed);
}

