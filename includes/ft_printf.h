/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:47:02 by apangraz          #+#    #+#             */
/*   Updated: 2021/10/14 10:47:02 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:54:50 by apangraz          #+#    #+#             */
/*   Updated: 2021/10/12 11:54:50 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_bag
{
	va_list	args;
	int		counter;
}		t_bag;

int		ft_printf(const char *str, ...);
void	ischar(t_bag *arg_count);
void	isstring(t_bag *arg_count);
void	isint(t_bag *arg_count);
void	isun_int(t_bag *arg_count);
void	ispointer(t_bag *arg_count);
void	ishex(t_bag *arg_count, char c);

#endif
