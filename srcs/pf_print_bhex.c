/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_bhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:57:32 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/14 02:17:38 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putchar(int n)
{
	char	c;

	c = (char)n;
	write(1, &c, 1);
}

unsigned int	print_bhex(unsigned long n)
{
	unsigned int	r;
	unsigned int	m;

	r = 0;
	m = 0;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar('0' + n);
		else
			ft_putchar('A' + n - 10);
		m++;
	}
	else
	{
		r = n % 16;
		m += print_bhex(n / 16);
		if (r < 10)
			ft_putchar(r + '0');
		else
			ft_putchar(r - 10 + 'A');
		m++;
	}
	return (m);
}

unsigned int	pf_print_bhex(unsigned long *n)
{
	return (print_bhex(*n));
}
