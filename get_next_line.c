#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*tail;
	int			check;

	line = NULL;
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	check = form_line(&line, &tail, &buff, fd);
	if (check == -1)
		return (free(buff), NULL);
	return (free(buff), line);
}

int	form_line(char **line, char **tail, char **buff, int fd)
{
	ssize_t	byte;
	int		ret;

	if (*tail != NULL)
	{
		*line = ft_realloc(*line, tail);
		if (!(*line))
			return (free (*tail), -1);
		ret = check_tail(tail);
		if (ret != 0)
			return (ret);
	}
	byte = read(fd, *buff, BUFFER_SIZE);
	while (byte > 0)
	{
		(*buff)[byte] = '\0';
		*line = ft_realloc(*line, buff);
		if (!(*line))
			return (-1);
		ret = upd_tail(buff, tail);
		if (ret != 0)
			return (ret);
		byte = read(fd, *buff, BUFFER_SIZE);
	}
	return (0);
}

int	check_tail(char **tail)
{
	char	*new_tail;
	size_t	ind_nl;
	size_t	len_tail;
	size_t	ind;

	len_tail = ft_strlen(*tail);
	ind_nl = find_nl(*tail);
	if (ind_nl == len_tail - 1 || ind_nl++ == len_tail)
		return  (free(*tail), *tail = NULL, 0);
	new_tail = (char *) malloc((len_tail - ind_nl + 1) * sizeof(char));
	if (!new_tail)
		return (free(*tail), -1);
	ind = 0;
	while ((*tail)[ind + ind_nl])
	{
		new_tail[ind] = (*tail)[ind + ind_nl];
		ind++;
	}
	new_tail[ind] = '\0';
	free(*tail);
	*tail = new_tail;
	return (1);
}

int	upd_tail(char **buff, char **tail)
{
	size_t	check_ind;
	size_t	ind;
	size_t	len_buff;

	check_ind = find_nl(*buff);
	len_buff = ft_strlen(*buff);
	if (check_ind == len_buff)
		return (0);
	if (check_ind == len_buff - 1)
		return (1);
	*tail = (char *) malloc((len_buff - check_ind) * sizeof(char));
	if (!(*tail))
		return (-1);
	ind = 0;
	while ((*buff)[check_ind + ind + 1])
	{
		(*tail)[ind] = (*buff)[check_ind + ind + 1];
		ind++;
	}
	(*tail)[ind] = '\0';
	return (1);
}
