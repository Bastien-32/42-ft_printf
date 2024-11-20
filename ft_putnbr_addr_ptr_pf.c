/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_addr_ptr_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:55:01 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/20 09:57:13 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_addr_ptr_pf(unsigned long nb, char *base)
{
	int		i;
	char	c;

	i = 0;
	if (nb >= (unsigned long)ft_strlen(base))
		i += ft_putnbr_addr_ptr_pf(nb / ft_strlen(base), base);
	c = base[nb % ft_strlen(base)];
	i += write(1, &c, 1);
	return (i);
}
