/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:19 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/14 21:40:28 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_str(char *a, int i);
int	ft_str_dot(char *s, int j, int precision);
int	ft_str_width_before(char *s, int j, int width_before, int precision);
int	ft_str_width_after(char *s, int j, int width_after, int precision);

int	ft_char(char c, int i);
int	ft_char_width_before(char c, int j, int width_before);
int	ft_char_width_after(char c, int j, int width_after);

int	ft_numlen(int n);
int	ft_num(int n, int j, char c);
int	ft_space_number_before(int n, int j, char c, int width);
int	ft_space_number_after(int n, int j, char c, int width);

int	ft_hexlen(size_t n);
int	ft_hexl(size_t n, int i, char c);
int	ft_hex_width_before(size_t n, int j, char c, int width_before);
int	ft_hex_width_after(size_t n, int j, char c, int width_after);

int	ft_hexu(size_t n, int i, char c);
int	ft_hexu_width_before(size_t n, int j, char c, int width_before);
int	ft_hexu_width_after(size_t n, int j, char c, int width_after);

int	ft_unslen(unsigned int n);
int	ft_uns(unsigned int n, int i);
int	ft_uns_width_before(unsigned int n, int j, int width_before);
int	ft_uns_width_after(unsigned int n, int j, int width_after);

int	ft_ptr(unsigned long nb, int j);
int	ft_print_ptr(unsigned long nb, int j);
int	ft_ptr_width_before(unsigned long ptr, int j, int width_before);
int	ft_ptr_width_after(unsigned long ptr, int j, int width_after);

int	ft_print_space(int size, int j);
int	ft_strlen(char *s);
int	ft_printf(const char *a, ...);
int	ft_next_precent(const char *format, va_list args, int j, int i);

#endif
