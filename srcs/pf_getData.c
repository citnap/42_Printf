/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getData.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:50:07 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/09 15:22:34 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#define t_assign_content(content, type) \
	do						\
	{						\
		content = malloc(sizeof(type));		\
		*((type *)content) = va_arg(arg, type); \
        }						\
	while(0)

char    *check_type(char *label)
{
        if (*label == 'c')
                return ("char");
        if (*label == 's')
                return ("str");
        if (*label == 'p')
                return ("ptr");
        if (*label == 'd' || *label == 'i')
                return ("int");
        if (*label == 'u')
                return ("unsigned int");
        if (*label == 'x')
                return ("hex");
        if (*label == 'X')
                return ("HEX");
        if (*label == '%')
                return ("char");
        return (NULL);
}

t_list  *make_data(va_list arg, char *data_type)
{
        void    *content;
        
        if (ft_strncmp(data_type, "char", 5) == 0)
                t_assign_content(content, int);
        else if (ft_strncmp(data_type, "str", 4) == 0)
                content = va_arg(arg, char*);
        else if (ft_strncmp(data_type, "ptr", 4) == 0)
                content = va_arg(arg, void*);
        else if (ft_strncmp(data_type, "int", 4) == 0)
                t_assign_content(content, int);
        else if (ft_strncmp(data_type, "unsigned int", 15) == 0)
                t_assign_content(content, unsigned int);
        else if (ft_strncmp(data_type, "hex", 4) == 0)
                t_assign_content(content, int);
        else if (ft_strncmp(data_type, "HEX", 4) == 0)
                t_assign_content(content, int);
        return (ft_lstnew(content, data_type));
}

t_list  **pf_getData(const char *fmt, va_list arg)
{
        t_list	**data;
	char		*front;
	char		*back;

	front = (char *)fmt;
	back = (char *)fmt;
	data = (t_list**)malloc(sizeof(t_list *));
        while (*front)
	{
		if (*front == '%' && front != back)
		{
			ft_lstadd_back(data, ft_lstnew(ft_substr(fmt, front - fmt, front - back + 1), "str"));
			back = front + 1;
		}
		if (*front == '%')
			ft_lstadd_back(data, ft_lstnew(make_data(arg, check_type(front + 1)), check_type(front + 1)));
		front++;			
	}

        return (NULL);
}