/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:43:40 by amelniko          #+#    #+#             */
/*   Updated: 2024/06/21 11:49:36 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_realloc(char *str, char **buff);
int		upd_tail(char **buff, char **tail);
size_t	find_nl(char *str);
int		ft_strlcat(char *dest, char *str, size_t size);
int		check_tail(char **tail);
int		form_line(char **line, char **tail, char **buff, int fd);
#endif
