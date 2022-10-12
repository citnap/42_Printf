/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_bhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:57:32 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/11 21:51:03 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

unsigned int	print_bhex(unsigned long n)
{
	char			r;
	unsigned int	m;

	m = 0;
	if (n < 16)
	{
		(n < 10) ? (ft_putchar_fd('0' + n, 1)) : (ft_putchar_fd('A' + n - 10, 1));
		m++;
	}
	else
	{
		r = n % 16;
		m += print_bhex(n / 16);
		if (r < 10)
			ft_putchar_fd(r + '0', 1);
		else
			ft_putchar_fd(r - 10 + 'A', 1);
		m++;
	}
	return (m);
}

unsigned int pf_print_bhex(unsigned long *n)
{
	return (print_bhex(*n));
}