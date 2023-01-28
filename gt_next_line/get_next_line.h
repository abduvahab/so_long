/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:14:07 by areheman          #+#    #+#             */
/*   Updated: 2022/04/04 14:23:37 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*get_line(char *s);
char	*ft_save(char *s);
char	*ft_read_save(char *save, int fd);
char	*fts_strjoin(char *s1, char *s2);
char	*fts_strchr(char *s, int c);
size_t	fts_strlen(char *s);

#endif
