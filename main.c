/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:01:13 by gadoglio          #+#    #+#             */
/*   Updated: 2021/05/11 20:54:15 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int			ft_read_t(char *str, int buffer_size)
{
	int		pipeline[2];
	char	buf[buffer_size];
	int		ret;

	bzero(buf, buffer_size);
	if (pipe(pipeline) < 0)
		exit(EXIT_FAILURE);
	fcntl(pipeline[0], F_SETFL, O_NONBLOCK);
	write(pipeline[1], str, strlen(str));
	ret = ft_read(pipeline[0], buf, buffer_size);
	buf[ret] = '\0';
	printf("str : \"%s\" / What was read : \"%s\"\n", str, buf);
	if (!strcmp(buf, str))
		printf("[OK]\n");
	else
		printf("[KO]\n");
	close(pipeline[1]);
	close(pipeline[0]);
	return (1);
}

int			ft_write_t(int buffer_size, char *str)
{
	int			pipeline[2];
	char		buf[buffer_size];
	int			ret;

	bzero(buf, buffer_size);
	if (pipe(pipeline) < 0)
		exit(EXIT_FAILURE);
	fcntl(pipeline[0], F_SETFL, O_NONBLOCK);
	ft_write(pipeline[1], str, strlen(str));
	ret = read(pipeline[0], buf, buffer_size);
	buf[ret] = '\0';
	errno = 0;
	printf("write : \"%s\" / ft_write : \"%s\"\n", str, buf);
	if (!strcmp(buf, str))
		printf("[OK]\n");
	else
		printf("[KO]\n");
	close(pipeline[1]);
	close(pipeline[0]);
	return (1);
}

int			ft_strcpy_t(int buffer_size, char *src)
{
	char	dst1[buffer_size];
	char	dst2[buffer_size];

	bzero(dst1, buffer_size);
	bzero(dst2, buffer_size);
	ft_strcpy(dst1, src);
	strcpy(dst2, src);
	printf("strcpy : %s / ft_strcpy : %s\n", dst2, dst1);
	if (!strcmp(dst1, dst2))
		printf("[OK]\n");
	else
		printf("[KO]\n");
	return (1);
}

int			ft_strcmp_t(char *s1, char *s2)
{
	int		ret1;
	int		ret2;

	ret2 = ft_strcmp(s1, s2);
	ret1 = strcmp(s1, s2);
	printf("strcmp : %d / ft_strcmp : %d\n", ret1, ret2);
	if (ret1 == ret2)
		printf("[OK]\n");
	else
		printf("[KO]\n");
	return (1);
}

int		main(void)
{
	int	ft;
	int	real;
	char *str;

	ft = 0;
	real = 0;
	str = "Hello, World!";
	real = strlen(str);
	ft = ft_strlen(str);
	printf("String: %s\n", str);
	printf("Official Lib Result: %i\n", real);
	printf("Libasm result: %i\n\n", ft);

	printf("%s", "ft_read.s\n");
	ft_read_t("Hellow World!", 40);
	ft_read_t("42", 40);
	ft_read_t("    ", 40);
	ft_read_t("", 40);
	ft_read_t("Hellow \nworld!", 40);
	ft_read_t("Hellow\0World", 40);
	printf("\n\n");

	/*
	** ft_write
	*/
	printf("%s", "ft_write.s\n");
	ft_write_t(40, "Hellow World!");
	ft_write_t(40, "42");
	ft_write_t(40, "    ");
	ft_write_t(40, "");
	ft_write_t(40, "Hellow \nworld!");
	ft_write_t(40, "Hellow\0World");
	printf("\n\n");

	/*
	** ft_strcpy
	*/
	printf("%s", "ft_strcpy.s\n");
	ft_strcpy_t(40, "Hellow World!");
	ft_strcpy_t(40, "\t@caps");
	ft_strcpy_t(40, "");
	ft_strcpy_t(40, " ");
	ft_strcpy_t(40, "Hellow\0 World!");
	printf("\n\n");

	/*
	** ft_strcmp
	*/
	printf("%s", "ft_strcmp.s\n");
	ft_strcmp_t("Hellow World!", "Hellow World!");
	ft_strcmp_t("Hellow", "World!");
	ft_strcmp_t("Hellow World!", "");
	ft_strcmp_t("", "Hellow World!");
	ft_strcmp_t("Hellow World!", " ");
	ft_strcmp_t("", "");
	ft_strcmp_t(" ", " ");
	ft_strcmp_t("uvaf", "uva");
	ft_strcmp_t("Hellow\0 World!", " crazy");
	printf("\n\n");


	return (0);
}