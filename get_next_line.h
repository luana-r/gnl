/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:31:33 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/02/03 17:59:14 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
char	*ft_strdup(char *c);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read(char *joined, int fd);
char	*ft_build_line(char *line);
char	*get_line_after_bslash_n(char *line);
char	*get_next_line(int fd);

#endif