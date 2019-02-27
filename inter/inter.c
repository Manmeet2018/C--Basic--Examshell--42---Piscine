/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intertest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:09:24 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/26 23:56:33 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_inter(char *a, char *b)
{
	int i = 0;
	char arr[127];
	while (b[i])
	{
		arr[(int)b[i]] = 1;
		i++;	
	}
	i = 0;
	while (a[i])
	{
		if(arr[(int)a[i]])
		{
			write(1, &a[i], 1);
			arr[(int)a[i]] = 0;
		}
		i++;
	}
}

int main (int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);
	}
	write (1, "\n", 1);
	return (0);
}