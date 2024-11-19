/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_addr_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:36:26 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/19 18:05:40 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_addr_ptr(unsigned long nb, char *base)
{
	int		i;
	char	c;

	i = 0;
	if (nb >= (unsigned long)ft_strlen(base))
		i += ft_putnbr_addr_ptr(nb / ft_strlen(base), base);
	c = base[nb % ft_strlen(base)];
	i += write(1, &c, 1);
	return (i);
}
