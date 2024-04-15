/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:34:18 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/15 22:03:58 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unslen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_uns(unsigned int n, int i)
{
	if (n == 0)
	{
		i = ft_char('0', i);
		return (i);
	}
	else if (n >= 10)
	{
		i = ft_num((n / 10), i, '\0');
		i = ft_num((n % 10), i, '\0');
	}
	else
	{
		i = ft_char(((n % 10) + '0'), i);
	}
	return (i);
}

int	ft_uns_width_before(unsigned int n, int i, t_flags flags)
{
	int	x;

	x = flags.width_before;
	if (flags.precision > 0)
	{
		flags.fill = '0';
		x = flags.precision;
	}
	i = ft_print_space(x - ft_unslen(n), i, flags.fill);
	i = ft_uns(n, i);
	return (i);
}

int	ft_uns_width_after(unsigned int n, int i, int width_after)
{
	i = ft_uns(n, i);
	i = ft_print_space(width_after - ft_unslen(n), i, ' ');
	return (i);
}