/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:10:57 by gleonell          #+#    #+#             */
/*   Updated: 2020/08/16 22:21:52 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
int		ft_slen(const char *str);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*exbuff_check(char **line, char **exbuff, int *bytes);

#endif
