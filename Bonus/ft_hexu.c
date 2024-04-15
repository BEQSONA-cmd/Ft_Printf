/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:23:43 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/14 22:34:10 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexu(size_t n, int j, char c)
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
		j = ft_hexu(i / 16, j, '\0');
		j = ft_hexu(i % 16, j, '\0');
	}
	else if (i < 10)
		j = ft_char(i + '0', j);
	else
		j = ft_char((i - 10) + 'A', j);
	return (j);
}

int	ft_hexu_width_before(size_t n, int j, char c, int width_before)
{
	int	i;

	i = n;
	if (c == '#' && n != 0)
		width_before -= 2;
	j = ft_print_space(width_before - ft_hexlen(n), j);
	j = ft_hexu(n, j, c);
	return (j);
}

int	ft_hexu_width_after(size_t n, int j, char c, int width_after)
{
	int	i;

	i = n;
	if (c == '#' && n != 0)
		width_after -= 2;
	j = ft_hexu(n, j, c);
	j = ft_print_space(width_after - ft_hexlen(n), j);
	return (j);
}
