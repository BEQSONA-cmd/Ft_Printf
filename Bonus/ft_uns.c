/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:34:18 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/14 22:34:04 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unslength(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
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

int	ft_uns_width_before(unsigned int n, int i, int width_before)
{
	i = ft_print_space(width_before - ft_unslength(n), i);
	i = ft_uns(n, i);
	return (i);
}

int	ft_uns_width_after(unsigned int n, int i, int width_after)
{
	i = ft_uns(n, i);
	i = ft_print_space(width_after - ft_unslength(n), i);
	return (i);
}