/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:22:07 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/19 18:05:14 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_address(unsigned long nb);

int	ft_putnbr(int n);

int	ft_putnbr_base(unsigned int nb, char *base);

int	ft_putnbr_addr_ptr(unsigned long nb, char *base);

int	ft_putnbr_pos(unsigned int n);

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_strlen(char *str);

int	ft_printf(const char *format, ...);

#endif