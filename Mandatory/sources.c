/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:09:15 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/14 22:25:59 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexl(size_t n, int i)
{
	unsigned int	j;

	j = (unsigned int)n;
	if (j == 0)
		i = ft_char('0', i);
	else if (j >= 16)
	{
		i = ft_hexl(j / 16, i);
		i = ft_hexl(j % 16, i);
	}
	else
	{
		if (n <= 9)
			i = ft_char(n + '0', i);
		else
			i = ft_char(n + 'a' - 10, i);
	}
	return (i);
}

int	ft_hexu(size_t n, int i)
{
	unsigned int	j;

	j = (unsigned int)n;
	if (j == 0)
		i = ft_char('0', i);
	else if (j >= 16)
	{
		i = ft_hexu(j / 16, i);
		i = ft_hexu(j % 16, i);
	}
	else
	{
		if (n <= 9)
			i = ft_char(n + '0', i);
		else
			i = ft_char(n + 'A' - 10, i);
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
		i = ft_num((n / 10), i);
		i = ft_num((n % 10), i);
	}
	else
	{
		i = ft_char(((n % 10) + '0'), i);
	}
	return (i);
}

int	ft_print_ptr(unsigned long nb, int j)
{
	if (nb >= 16)
	{
		j = ft_print_ptr((nb / 16), j);
		j = ft_print_ptr((nb % 16), j);
	}
	else
	{
		if (nb <= 9)
			j = ft_char((nb + '0'), j);
		else
			j = ft_char((nb - 10 + 'a'), j);
	}
	return (j);
}

int	ft_ptr(unsigned long ptr, int j)
{
	j = ft_str("0x", j);
	if (ptr == 0)
		j = ft_char('0', j);
	else
	{
		j = ft_print_ptr(ptr, j);
	}
	return (j);
}