/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:47:31 by apangraz          #+#    #+#             */
/*   Updated: 2021/10/13 16:00:30 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*numlen(unsigned long n, int *len);

void	ispointer(t_bag *arg_count)
{
	int				len;
	char			*str;
	unsigned long	n;

	n = va_arg(arg_count->args, unsigned long);
	len = 1;
	str = numlen(n, &len);
	ft_putstr_fd("0x", 1);
	arg_count->counter += 2;
	len--;
	while (len >= 0)
	{
		if (n % 16 <= 10)
			str[len] = '0' + (n % 16);
		else
			str[len] = 'W' + (n % 16);
		n = n / 16;
		len--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ishex(t_bag *arg_count, char c)
{
	unsigned int	n;
	int				len;
	char			*str;

	n = va_arg(arg_count->args, unsigned int);
	len = 1;
	str = numlen(n, &len);
	len--;
	while (len >= 0)
	{
		if (n % 16 < 10)
			str[len] = '0' + (n % 16);
		else if (c == 'x')
			str[len] = 'a' - 10 + (n % 16);
		else if (c == 'X')
			str[len] = 'A' - 10 + (n % 16);
		n = n / 16;
		len--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

static char	*numlen(unsigned long n, int *len)
{
	char	*str;

	while (n >= 16)
	{
		n = n / 16;
		*len += 1;
	}
	str = (char *)malloc((*len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[*len] = '\0';
	return (str);
}
