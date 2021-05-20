/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_strcpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:28:19 by nfranco-          #+#    #+#             */
/*   Updated: 2021/05/16 23:39:20 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test(char *src)
{
	char	dst[600];

	bzero(dst, 600);
	printf("src       = \"%s\"\n\n", src);
	printf("dst value = \"%s\"\n", dst);
	printf("dst addr  = %p\n", dst);
	printf("strcpy    = \"%s\"\n", strcpy(dst, src));
	printf("return    = %p\n\n", dst);
	bzero(dst, 600);
	printf("dst value = \"%s\"\n", dst);
	printf("dst addr  = %p\n", dst);
	printf("ft_strcpy    = \"%s\"\n", ft_strcpy(dst, src));
	printf("return    = %p\n\n", dst);
	bzero(dst, 600);
	printf("----------------------------\n");
}

void	test_ft_strcpy(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_STRCPY  ~~~~~~\e[0m\n\n");
	test("Hello World");
	test("");
	test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. In dapibus\
	 ultrices nunc et faucibus. Sed id cursus sem. Quisque porttitor ipsum \
	 vitae dui suscipit ullamcorper. Nulla interdum libero elit, sed porta mi \
	 aliquam ac. Fusce vulputate aliquet libero eu egestas. Morbi porttitor, \
	 tortor quis laoreet luctus, nibh justo congue metus, sit amet aliquet \
	 sem magna id dui. Sed maximus dolor vel quam condimentum tristique. Donec\
	  volutpat ligula at nibh gravida, at fringilla magna molestie. Morbi \
	  vitae convallis nunc.");
	test("abcdef\0---34567");
}
