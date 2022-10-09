/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:57:27 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/07 20:35:30 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <inttypes.h>

void     pf_printptr(void *ptr)
{
        uintptr_t       n;
        n = (uintptr_t)ptr;
        pf_printHex(n);
        return ;
}