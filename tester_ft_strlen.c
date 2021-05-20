/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:27:07 by nfranco-          #+#    #+#             */
/*   Updated: 2021/05/16 23:40:48 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test(char *str)
{
	printf("string    = \"%s\"\n\n", str);
	printf("strlen    = %lu\n", strlen(str));
	printf("ft_strlen = %lu\n", ft_strlen(str));
	printf("----------------------------\n");
}

void	test_ft_strlen(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_STRLEN  ~~~~~~\e[0m\n\n");
	test("Hello World");
	test("\ttesting ft_strlen");
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
	test("   ");
}
