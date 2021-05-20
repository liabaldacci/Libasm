/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:19:05 by gadoglio          #+#    #+#             */
/*   Updated: 2021/05/19 20:38:39 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <errno.h>

int			main(void);
size_t		ft_strlen(const char *s);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
char		*ft_strdup(const char *s);
void		test_ft_read(void);
void		test_ft_strcmp(void);
void		test_ft_strcpy(void);
void		test_ft_strdup(void);
void		test_ft_strlen(void);
void		test_ft_write(void);

#endif
