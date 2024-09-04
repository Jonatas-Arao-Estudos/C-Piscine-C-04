/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:42:40 by jarao-de          #+#    #+#             */
/*   Updated: 2024/09/04 10:33:12 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_base_num(char str, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == str)
			return (index);
		index = index + 1;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	index;
	int	sign;
	int	base_n;

	if (ft_check_base(base) == 0)
		return (0);
	index = 0;
	num = 0;
	base_n = ft_strlen(base);
	sign = 1;
	while (str[index] == ' ' || str[index] == '\f' || str[index] == '\n'
		|| str[index] == '\r' || str[index] == '\t' || str[index] == '\v')
		index = index + 1;
	while (str[index] == '+' || str[index] == '-'
		|| ft_base_num(str[index], base) != -1)
	{
		if (str[index] == '-')
			sign = sign * (-1);
		else if (str[index] != '+')
			num = ft_base_num(str[index], base) + num * base_n;
		index = index + 1;
	}
	return (num * sign);
}
