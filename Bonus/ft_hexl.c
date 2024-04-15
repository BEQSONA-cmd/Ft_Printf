/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:17:15 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/15 22:03:38 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(long n)
{
	int				i;
	unsigned long	j;

	i = 0;
	j = (unsigned long)n;
	if (n == -9223372036854775807L - 1L || j == 9223372036854775807L * 2UL
		+ 1UL)
		return (16);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_hexl(size_t n, int j, char c)
{
	unsigned int	i;

	i = (unsigned int)n;
	if (c == '#' && i != 0)
	{
		j = ft_char('0', j);
		j = ft_char('x', j);
	}
	if (i == 0)
		j = ft_char('0', j);
	else if (i >= 16)
	{
		j = ft_hexl(i / 16, j, '\0');
		j = ft_hexl(i % 16, j, '\0');
	}
	else if (i < 10)
		j = ft_char(i + '0', j);
	else
		j = ft_char((i - 10) + 'a', j);
	return (j);
}

int	ft_hex_width_before(size_t n, int j, char c, t_flags flags)
{
	unsigned int	i;
	int				x;

	i = (unsigned int)n;
	x = flags.width_before;
	if (flags.precision > 0)
	{
		flags.fill = '0';
		x = flags.precision;
	}
	if (c == '#' && n != 0)
		flags.width_before -= 2;
	j = ft_print_space(x - ft_hexlen(i), j, flags.fill);
	j = ft_hexl(i, j, c);
	return (j);
}

int	ft_hex_width_after(size_t n, int j, char c, int width_after)
{
	unsigned int	i;

	i = (unsigned int)n;
	if (c == '#' && n != 0)
		width_after -= 2;
	j = ft_hexl(i, j, c);
	j = ft_print_space(width_after - ft_hexlen(i), j, ' ');
	return (j);
}
