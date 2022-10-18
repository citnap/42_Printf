/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:08:40 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/11 15:11:48 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

unsigned int	pf_putstr(char *c)
{
	unsigned int	n;

	n = 0;
	if (*c)
	{
		n += pf_putchar(c);
		n += pf_putstr(c + 1);
	}
	return (n);
}
