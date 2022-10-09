/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printHex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:57:32 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/07 20:35:25 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void    printHex(unsigned long long n)
{
        char    r;

        if (n <= 16)
                (n < 10) ? (ft_putchar_fd('0' + n, 1)) : (ft_putchar_fd('a' + n - 10, 1));
        else
        {
                r = n % 16;
                printHex(n / 16);
                (r < 10) ? (ft_putchar_fd('0' + r, 1)) : (ft_putchar_fd('a' + r - 10, 1));
        }
        return ;
}

void    pf_printHex(unsigned long long n)
{
        ft_putstr_fd("0x", 1);
        printHex(n);
        return ;
}