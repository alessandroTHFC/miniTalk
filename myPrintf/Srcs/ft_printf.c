/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:47:31 by apangraz          #+#    #+#             */
/*   Updated: 2021/10/13 15:57:51 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bag	*initialise(void);
void			typechecker(const char c, t_bag *arg_count);

int	ft_printf(const char *str, ...)
{
	t_bag	*arg_count;
	int		totalprinted;
	int		i;

	i = 0;
	arg_count = initialise();
	totalprinted = 0;
	va_start(arg_count->args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			typechecker(str[++i], arg_count);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			arg_count->counter++;
		}
		i++;
	}
	totalprinted = arg_count->counter;
	va_end(arg_count->args);
	free(arg_count);
	return (totalprinted);
}

static t_bag	*initialise(void)
{
	t_bag	*arg_count;

	arg_count = (t_bag *)malloc(sizeof(t_bag));
	if (arg_count == NULL)
		return (NULL);
	arg_count->counter = 0;
	return (arg_count);
}

void	typechecker(const char c, t_bag *arg_count)
{
	if (c == 'i' || c == 'd')
		isint(arg_count);
	else if (c == 'c')
		ischar(arg_count);
	else if (c == 's')
		isstring(arg_count);
	else if (c == 'u')
		isun_int(arg_count);
	else if (c == 'p')
		ispointer(arg_count);
	else if (c == 'x' || c == 'X')
		ishex(arg_count, c);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		arg_count->counter++;
	}
}
