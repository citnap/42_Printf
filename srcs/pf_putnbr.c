/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:13:23 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/14 15:26:29 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

unsigned int	lenlen(int n)
{
	unsigned int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

unsigned int	pf_putnbr(int *n)
{
	unsigned int	len;
	int				org;
	int				tmp;

	org = *n;
	tmp = org;
	len = 0;
	if (org == -2147483648)
		len = 11;
	else if (org < 0)
	{
		org = org * -1;
		len++;
	}
	len += lenlen(org);
	ft_putnbr_fd(tmp, 1);
	return (len);
}
