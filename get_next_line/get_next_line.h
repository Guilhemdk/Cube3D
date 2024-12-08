/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:09:05 by pitroin           #+#    #+#             */
/*   Updated: 2024/08/01 17:54:27 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

int		ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *s, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strndup_gnl(char *s, int n);
char	*get_next_line(int fd);
char	*read_fd(int fd, char **current, char **buff);
char	*last_line(char **current, char **line);
char	*extract_line(char **current);

#endif
