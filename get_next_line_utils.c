/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:43:53 by amelniko          #+#    #+#             */
/*   Updated: 2024/06/21 11:43:54 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *str, char **buff)
{
	size_t	len_line;
	char	*ret_line;
	size_t	check_ind;

	len_line = ft_strlen(str);
	check_ind = find_nl(*buff);
	if (ft_strlen(*buff) == check_ind)
		ret_line = (char *) malloc((len_line + check_ind + 1) * sizeof(char));
	else
		ret_line = (char *) malloc((len_line + check_ind + 2) * sizeof(char));
	if (!ret_line)
		return (NULL);
	ret_line[0] = '\0';
	ft_strlcat(ret_line, str, len_line + 1);
	ft_strlcat(ret_line, *buff, check_ind + 2);
	free(str);
	return (ret_line);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	if (!s)
		return (0);
	index = 0;
	while (s[index])
		index++;
	return (index);
}

int	ft_strlcat(char *dest, char *str, size_t size)
{
	size_t	ind_str;
	size_t	ind_dest;

	ind_dest = 0;
	while (dest[ind_dest])
		ind_dest++;
	ind_str = 0;
	while (ind_str < size - 1 && str[ind_str])
	{
		dest[ind_dest + ind_str] = str[ind_str];
		ind_str++;
	}
	dest[ind_dest + ind_str] = '\0';
	return (ind_dest + ind_str);
}

size_t	find_nl(char *str)
{
	size_t	ind;

	ind = 0;
	while (str[ind] && str[ind] != '\n')
		ind++;
	return (ind);
}
