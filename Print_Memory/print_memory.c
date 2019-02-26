/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memorytest2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:38:22 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/25 23:14:05 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void ft_print_hex(int x)
{
	char *base = "0123456789abcdef";

	write(1, &base[x / 16], 1);
	write (1, &base[x % 16], 1);
}


void ft_putchar(char c)
{
	if (c >= 32 && c <= 127)
		write(1, &c, 1);
	write (1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i = 0;
	size_t j;

	unsigned char const *p = addr;

	while (i < size)
	{
		j = 0;
		while ( j < 16 && i + j < size)
		{
			ft_print_hex(*(p + i + j));
			if (j % 2)
				write (1, " ", 1);
			j++;
		}
		while ( j < 16)
		{
			write (1, "  ", 2);
			if (j % 2)
				write (1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			ft_putchar(*(p + i + j));
			j++;
		}
		write (1, "\n", 1);
		i += 16;
	}
}
