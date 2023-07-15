/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:58:17 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/15 15:06:11 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	how_many_digits_1(long long nbr, int base_len)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	else if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	char		*ret;
	int			ret_len;
	int			i;

	nbr = (long long)n;
	ret_len = how_many_digits_1(nbr, 10);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (ret == 0)
		return (0);
	if (nbr == 0)
		ret[0] = '0';
	else if (nbr < 0)
	{
		nbr *= -1;
		ret[0] = '-';
	}
	i = 0;
	while (nbr > 0)
	{
		ret[ret_len - 1 - i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	ret[ret_len] = 0;
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (*ptr1 || *ptr2)
	{
		if (*ptr1 != *ptr2)
			return ((*ptr1 - *ptr2));
		ptr1++;
		ptr2++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ch = (char)c;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == ch)
			return (ptr);
		ptr++;
	}
	if (ch == '\0')
		return (ptr);
	return (0);
}
