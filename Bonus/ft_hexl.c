/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:17:15 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/14 22:34:08 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
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
	if (c == '#' && n != 0)
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

int	ft_hex_width_before(size_t n, int j, char c, int width_before)
{
	int	i;

	i = n;
	if (c == '#' && n != 0)
		width_before -= 2;
	j = ft_print_space(width_before - ft_hexlen(i), j);
	j = ft_hexl(i, j, c);
	return (j);
}

int	ft_hex_width_after(size_t n, int j, char c, int width_after)
{
	int	i;

	i = n;
	if (c == '#' && n != 0)
		j = ft_char('0', j);
	j = ft_hexl(i, j, c);
	j = ft_print_space(width_after - ft_hexlen(i), j);
	return (j);
}
