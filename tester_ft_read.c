/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:30:36 by nfranco-          #+#    #+#             */
/*   Updated: 2021/05/16 23:40:17 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test_orig(int fd, char *buffer)
{
	int	ret;

	bzero(buffer, 101);
	ret = read(fd, buffer, 100);
	buffer[ret] = '\0';
	printf("read buffer    = \"%s\"\n", buffer);
	printf("read return    = %d\n", ret);
}

static void	test_implem(int fd, char *buffer)
{
	int	ret;

	bzero(buffer, 101);
	ret = ft_read(fd, buffer, 100);
	buffer[ret] = '\0';
	printf("ft_read buffer = \"%s\"\n", buffer);
	printf("ft_read return = %d\n", ret);
}

void	test_ft_read(void)
{
	char	buffer[101];
	int		fd;

	printf("\n\n\e[1;1m~~~~~~  FT_READ  ~~~~~~\e[0m\n");
	printf("\n\e[4m  STANDART INPUT  \e[0m\n\n");
	test_orig(STDIN_FILENO, buffer);
	test_implem(STDIN_FILENO, buffer);
	printf("----------------------------\n");
	printf("\n\e[4m  OPEN FILE DESCRIPTOR  \e[0m\n\n");
	fd = open("read_file.txt", O_RDWR);
	test_orig(fd, buffer);
	close(fd);
	fd = open("read_file.txt", O_RDWR);
	test_implem(fd, buffer);
	close(fd);
	printf("----------------------------\n");
	printf("\n\e[4m  WRONG FILE DESCRIPTOR  \e[0m\n\n");
	fd = open("read_file.txt", O_RDWR);
	test_orig(fd + 5, buffer);
	close(fd);
	fd = open("main_read.txt", O_RDWR);
	test_implem(fd + 5, buffer);
	close(fd);
}
