/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:16:50 by stak              #+#    #+#             */
/*   Updated: 2024/02/16 17:10:18 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}

int	ft_sign(char n)
{
	if (n == '+' || n == '-')
	{
		if (n == '-')
			n *= -1;
		n++;
	}
	return (0);
}

static int	check_overflow(long int i, long int check, long int sign)
{
	if (i > check && sign < 0)
		return (0);
	if (i < check && sign > 0)
		return (-1);
	return (1);
}

long int	ft_atoi(const char *str)
{
	long int	i;
	long		sign;
	long		check;
	int			over;

	i = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		check = i;
		i = i * 10 + sign * (*str - '0');
		str++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	i = 0;
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	while (i < n && (uc1[i] != 0 || uc2[i] != 0))
	{
		if (uc1[i] > uc2[i])
		{
			return (uc1[i] - uc2[i]);
		}
		else if (uc1[i] < uc2[i])
		{
			return (uc1[i] - uc2[i]);
		}
		i++;
	}
	return (0);
}

int	ft_checker(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && (!ft_sign(argv[i])))
			return (0);
		i++;
	}
	return (1);
}

int ft_dup_check(char **argv, int i)
{
	int	j;

	j = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && i != j)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
