/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:37:14 by jarao-de          #+#    #+#             */
/*   Updated: 2024/09/04 11:08:02 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	unsigned int	index;
	int				num;
	int				sign;

	index = 0;
	num = 0;
	sign = 1;
	while (str[index] == ' ' || str[index] == '\f' || str[index] == '\n'
		|| str[index] == '\r' || str[index] == '\t' || str[index] == '\v')
		index = index + 1;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = sign * (-1);
		index = index + 1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		num = (str[index] - '0') + num * 10;
		index = index + 1;
	}
	return (num * sign);
}
