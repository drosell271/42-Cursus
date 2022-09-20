/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:39:18 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/20 10:34:38 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strchr(const char *s, int c)
{
	int	count;
	int	pos;

	count = 0;
	while (s[c] != '\0')
	{
		if (s[c] == c)
		{
			return (count);
		}
		count++;
	}
	return (count);
}
