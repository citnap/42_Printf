/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:50:07 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/14 17:52:52 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*check_type(char *label)
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
		return ("%");
	return (NULL);
}
int	is_int(char *type)
{
	if (ft_strncmp(type, "int", 4) == 0)
		return (1);
	else if (ft_strncmp(type, "char", 5) == 0)
		return (1);
	return (0);
}

int	is_uint(char *data_type)
{
	if (ft_strncmp(data_type, "hex", 4) == 0)
		return (1);
	else if (ft_strncmp(data_type, "HEX", 4) == 0)
		return (1);
	else if (ft_strncmp(data_type, "unsigned int", 15) == 0)
		return (1);
	return (0);
}

t_list	*make_data(va_list arg, char *data_type)
{
	void	*content;

	if (is_int(data_type))
	{
		content = malloc(sizeof(int));
		*(int *)content = va_arg(arg, int);
	}
	else if (ft_strncmp(data_type, "%", 2) == 0)
	{
		content = malloc(sizeof(char));
		*(char *)content = '%';
	}
	else if (ft_strncmp(data_type, "str", 4) == 0)
		content = pf_get_str(arg);
	else if (ft_strncmp(data_type, "ptr", 4) == 0)
		content = va_arg(arg, void *);
	else if (is_uint(data_type))
	{
		content = malloc(sizeof(unsigned int));
		*((unsigned int *)content) = va_arg(arg, unsigned int);
	}
	else
		return (NULL);
	return (ft_lstnew(content, data_type));
}

t_list	**pf_get_data(char *fmt, va_list arg)
{
	t_list	**data;
	char	*back;
	char	*type;

	back = (char *)fmt;
	data = (t_list **)malloc(sizeof(t_list *));
	*data = NULL;
	while (*fmt)
	{
		if (*fmt == '%' && fmt != back && fmt[1])
			ft_lstadd_back(data, pf_getdata_str(back, fmt));
		if (*fmt == '%')
		{
			type = check_type(++fmt);
			if (type)
				ft_lstadd_back(data, make_data(arg, type));
			back = fmt + 1;			
		}
		fmt++;
	}
	if (fmt != back)
		ft_lstadd_back(data, pf_getdata_str(back, fmt));
	return (data);
}