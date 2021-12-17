/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:47:31 by apangraz          #+#    #+#             */
/*   Updated: 2021/10/12 11:47:31 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*uitoa(unsigned int n);
static int	numlen(unsigned int n);

void	isint(t_bag *arg_count)
{
	char	*str;
	int		value;

	value = va_arg(arg_count->args, int);
	str = ft_itoa(value);
	ft_putstr_fd(str, 1);
	arg_count->counter += ft_strlen(str);
	free(str);
}

void	isun_int(t_bag *arg_count)
{
	char			*str;
	unsigned int	value;

	value = va_arg(arg_count->args, unsigned int);
	str = uitoa(value);
	ft_putstr_fd(str, 1);
	arg_count->counter += ft_strlen(str);
	free(str);
}

static char	*uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = numlen(n);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

static int	numlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
