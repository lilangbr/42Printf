/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int            main()
{
    int qtt;
    char c = 'C';
    char d = '\0';
    char *p;
    char *q;
    char *s = "alo vc!!";


    p = &c;
    q = &d;


    printf("\n\n\n");
    qtt = printf("|%-16.4i|\n", 47);
    printf("%d caracteres impressos\n\n", qtt);
    qtt = ft_printf("|%-16.4i|\n", 47);
    printf("%d caracteres impressos\n\n", qtt);
    
    printf("\n\n\n");
    qtt = printf("|%16.4u|\n", -34);
    printf("%d caracteres impressos\n\n", qtt);
    qtt = ft_printf("|%16.4u|\n", -34);
    printf("%d caracteres impressos\n\n", qtt);

    printf("\n\n\n");
    qtt = printf("|%-16.4X|\n", 0xf56);
    printf("%d caracteres impressos\n\n", qtt);
    qtt = ft_printf("|%-16.4X|\n", 0xf56);
    printf("%d caracteres impressos\n\n", qtt);
    
    printf("\n\n\n");
    qtt = printf("|%-16p|\n", &s);
    printf("%d caracteres impressos\n\n", qtt);
    qtt = ft_printf("|%-16p|\n", &s);
    printf("%d caracteres impressos\n\n", qtt);
    
    printf("\n\n\n");
    qtt = printf("|%-16.4s|\n", s);
    printf("%d caracteres impressos\n\n", qtt);
    qtt = ft_printf("|%-16.4s|\n", s);
    printf("%d caracteres impressos\n\n", qtt);

    printf("\n\n\n");
    qtt = printf("|%8c|\n", 34);
    printf("%d caracteres impressos\n\n", qtt);
    qtt = ft_printf("|%8c|\n", 34);
    printf("%d caracteres impressos\n\n", qtt);


    return (0);
}

