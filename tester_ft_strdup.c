/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:31:35 by nfranco-          #+#    #+#             */
/*   Updated: 2021/05/16 23:39:10 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test(char *str)
{
	char	*ptr;

	errno = 0;
	ptr = NULL;
	printf("ptr value       = \"%s\"\n", ptr);
	printf("ptr addr        = %p\n", ptr);
	ptr = strdup(str);
	printf("strdup          = \"%s\"\n", ptr);
	printf("ptr addr        = %p\n", ptr);
	printf("strdup errno    = %d\n\n", errno);
	free(ptr);
	errno = 0;
	ptr = NULL;
	printf("ptr value       = \"%s\"\n", ptr);
	printf("ptr addr        = %p\n", ptr);
	ptr = ft_strdup(str);
	printf("ft_strdup       = \"%s\"\n", ptr);
	printf("ptr addr        = %p\n", ptr);
	printf("ft_strdup errno = %d\n\n", errno);
	free(ptr);
	errno = 0;
	printf("----------------------------\n");
}

void	test_ft_strdup(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_STRDUP  ~~~~~~\e[0m\n\n");
	test("");
	test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. In dapibus\
	 ultrices nunc et faucibus. Sed id cursus sem. Quisque porttitor ipsum \
	 vitae dui suscipit ullamcorper. Nulla interdum libero elit, sed porta mi \
	 aliquam ac. Fusce vulputate aliquet libero eu egestas. Morbi porttitor, \
	 tortor quis laoreet luctus, nibh justo congue metus, sit amet aliquet \
	 sem magna id dui. Sed maximus dolor vel quam condimentum tristique. Donec\
	  volutpat ligula at nibh gravida, at fringilla magna molestie. Morbi \
	  vitae convallis nunc.");
}
