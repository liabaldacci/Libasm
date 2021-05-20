/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_strcmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:29:24 by nfranco-          #+#    #+#             */
/*   Updated: 2021/05/16 23:38:46 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test(char *s1, char *s2)
{
	printf("s1        = \"%s\"\n", s1);
	printf("s2        = \"%s\"\n\n", s2);
	printf("strcmp    = %d\n", strcmp(s1, s2));
	printf("ft_strcmp = %d\n", ft_strcmp(s1, s2));
	printf("----------------------------\n");
}

void	test_ft_strcmp(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_STRCMP  ~~~~~~\e[0m\n\n");
	test("Hello World", "");
	test("", "Hello World");
	test("", "");
	test("test\ting", "test\ting");
	test("1234\0p1234", "1234\0abcdef");
}
