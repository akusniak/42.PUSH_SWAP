/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:44:11 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:54:04 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*ft_read_copy(int fd, char *save);
char	*ft_extract(char *save);
char	*ft_new_save(char *save);
char	*ft_strjoin_gnl(char *save, char *buffer);
char	*ft_gnl(int fd);

#endif
