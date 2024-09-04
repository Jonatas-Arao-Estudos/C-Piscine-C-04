/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:57:45 by jarao-de          #+#    #+#             */
/*   Updated: 2024/09/04 09:41:50 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index = index + 1;
	}
	return (index);
}

int	ft_check_base(char *base)
{
	unsigned int	index;
	unsigned int	jump;

	index = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		if (base[index] <= 32 || base[index] > 126)
			return (0);
		jump = index + 1;
		while (base[jump] != '\0')
		{
			if (base[index] == base[jump])
				return (0);
			jump = jump + 1;
		}
		index = index + 1;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_n;

	if (ft_check_base(base) != 0)
	{
		base_n = ft_strlen(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
			if (nbr == -2147483648)
			{
				ft_putnbr_base(((nbr - nbr % base_n) / base_n) * (-1), base);
				nbr = nbr % base_n;
			}
			nbr = nbr * (-1);
		}
		if (nbr >= base_n)
		{
			ft_putnbr_base(nbr / base_n, base);
			nbr = nbr % base_n;
		}
		if (nbr < base_n)
		{
			write(1, &base[nbr % base_n], 1);
		}
	}
}
