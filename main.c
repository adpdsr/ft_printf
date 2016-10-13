/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:45:30 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/13 18:32:51 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <wchar.h>
#include <limits.h>

int			main(void)
{	
	int		ret;
/*	char	*ptr;	
	void	*ptr2;
	void	*ptr3;

	ptr = NULL;
	ptr2 = "qszdaze";
	ptr3 = 0;

	printf("--- RET ----------------------------------\n\n");

	printf("printf    : [%d]\n", printf("%-10.2s %10d %% = ", "salut", 12));
	ft_printf("ft_printf : [%d]\n", ft_printf("%-10.2s %10d %% = ", "salut", 12));

	printf("printf    : [%d]\n", printf("%#10x %-20X %.2o = ", 321321, 12, 654654));
     	ft_printf("ft_printf : [%d]\n", ft_printf("%#10x %-20X %.2o = ", 321321, 12, 654654));
	
	printf("printf    : [%d]\n", printf("%-10.2u %10s %d = ", 321321, "salut", 12));
	ft_printf("ft_printf : [%d]\n", ft_printf("%-10.2u %10s %d = ", 321321, "salut", 12));
	ft_printf("\n");

	printf("--- INT ----------------------------------\n\n");

	printf("printf    : %#x\n", 0);
	ft_printf("ft_printf : %#x\n\n", 0);

	printf("printf    : [%d %i %d %i]\n", 123456, 789101112, -123987, -654987321);
	ft_printf("ft_printf : [%d %i %d %i]\n\n", 123456, 789101112, -123987, -654987321);
	
	printf("printf    : [%ld %li]\n", 12345613246, -789101112987654);
	ft_printf("ft_printf : [%ld %li]\n\n", 12345613246, -789101112987654);
	
	printf("printf    : [%+08d|%+i|%25.10ld]\n", -13200, 12, -20202020202020);
	ft_printf("ft_printf : [%+08d|%+i|%25.10ld]\n\n", -13200, 12, -20202020202020);
	
	printf("printf    : [%-25d %+i %-25.10ld]\n", -13200, 12, -20202020202020);
	ft_printf("ft_printf : [%-25d %+i %-25.10ld]\n\n", -13200, 12, -20202020202020);

	printf("printf    : [%+d %.0i %020i %-2.6ld]\n", 13200, 0, 0, -20202020202020);
	ft_printf("ft_printf : [%+d %.0i %020i %-2.6ld]\n\n", 13200, 0, 0, -20202020202020);
	
	printf("printf    : [%-8.d %+.i]\n", 13200, 13);
	ft_printf("ft_printf : [%-8.d %+.i]\n\n", 13200, 13);
	
	printf("--- STRING -------------------------------\n\n");

	ret = printf("printf    : [%s %s]\n", "aze", "qsdqsd");
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%s %s]\n", "aze", "qsdqsd");
	printf("ret = [%d]\n", ret);
	
	ret = printf("printf    : [%.2s %-.6s]\n", "azeazeaze", "qsdqsdqsd");
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%.2s %-.6s]\n", "azeazeaze", "qsdqsdqsd");
	printf("ret = [%d]\n", ret);

	ret = printf("printf    : [%12.2s %-15.6s]\n", "azeazeaze", "qsdqsdqsd");
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%12.2s %-15.6s]\n", "azeazeaze", "qsdqsdqsd");
	printf("ret = [%d]\n", ret);
	
	ret = printf("printf    : [%2s %s %-.2s %s]\n", "a", ptr, "yo", ptr);
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%2s %s %-.2s %s]\n", "a", ptr, "yo", ptr);
	printf("ret = [%d]\n", ret);

	ret = printf("printf    : [%-12.5s]\n", "0123456 azertyuiop");	
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%-12.5s]\n", "0123456 azertyuiop");	
	printf("ret = [%d]\n\n", ret);


	printf("--- CHAR ---------------------------------\n\n");

	ret = printf("printf    : [%-5c %c %6c %-2c %c %%]\n", 'a', 'b', 'c', 'd', ' ');
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%-5c %c %6c %-2c %c %%]\n", 'a', 'b', 'c', 'd', ' ');
	printf("ret = [%d]\n", ret);

	ret = printf("printf    : [%2c %c %-6c %2c %c %%]\n", 'a', 'b', 'c', 'd', 'z');
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%2c %c %-6c %2c %c %%]\n", 'a', 'b', 'c', 'd', 'z');
	printf("ret = [%d]\n\n", ret);


	printf("--- WCHAR --------------------------------\n\n");
	
	ret = printf("printf       : [%c %lc %5lc]\n", '@', '@', '^');
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf    : [%c %lc %5lc]\n", '@', '@', '^');
	printf("ret = [%d]\n", ret);

	ret = printf("printf       : [%-4c %2lc %-1lc]\n", '@', '@', '^');
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf    : [%-4c %2lc %-1lc]\n", '@', '@', '^');
	printf("ret = [%d]\n\n", ret);

	printf("--- HEXA ---------------------------------\n\n");

	printf("printf    : [%-20x %#020X]\n", 123456789, -321654987);
	ft_printf("ft_printf : [%-20x %#020X]\n\n", 123456789, -321654987);
	
	printf("printf    : [%#-20.2x|%-20X]\n", 123456789, -321654987);
	ft_printf("ft_printf : [%#-20.2x|%-20X]\n\n", 123456789, -321654987);

	printf("printf    : [%#-20.2x|%-10.6X]\n", 98798798, -132);
	ft_printf("ft_printf : [%#-20.2x|%-10.6X]\n\n", 98798798, -132);

	printf("--- OCTAL --------------------------------\n\n");
	
	ret = printf("printf    : [%-30lo|%#.5lo]\n", 13985643538, 135448367687168);
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%-30lo|%#.5lo]\n", 13985643538, 135448367687168);
	printf("ret = [%d]\n", ret);

	ret = printf("printf    : [%#10o|%-10.6lo|%040lo]\n", 321654, 135448367687168, 20202020202020);
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%#10o|%-10.6lo|%040lo]\n", 321654, 135448367687168, 20202020202020);
	printf("ret = [%d]\n", ret);

	ret = printf("printf    : [%.2o|%20.4lo|%.1lo]\n", 321654, 135448367321, 20202020202020);
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%.2o|%20.4lo|%.1lo]\n", 321654, 135448367321, 20202020202020);
	printf("ret = [%d]\n\n", ret);

	printf("--- UNSIGNED -----------------------------\n\n");
	
	ret = printf("printf    : [%0u %40u]\n", 123456789, 987654321);
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%0u %40u]\n", 123456789, 987654321);
	printf("ret = [%d]\n", ret);
	
	ret = printf("printf    : [%-10.5u|%020u]\n", 123456789, 987654321);
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%-10.5u|%020u]\n", 123456789, 987654321);
	printf("ret = [%d]\n\n", ret);

	printf("--- INT ----------------------------------\n\n");
	printf("printf    : [test0 %+08d %+i %20ld]\n", -13200, 12, -20202020202020);	
	ft_printf("ft_printf : [test0 %+08d %+i %20ld]\n\n", -13200, 12, -20202020202020);	
*/	
//	printf("--- WSTR ---------------------------------\n\n");
//	printf(L"printf    : [%30ls %.5ls]\n", L"æ«€¶ŧ←↓→øþ", L"@ßðđŋħłµł»¢“”n");
//	ft_printf("ft_printf : [%-30ls %.5S]\n\n", L"æ«€¶ŧ←↓→øþ", L"@ßðđŋħłµł»¢“”n");
/*		
	printf("--- PTR ----------------------------------\n\n");
	
	ret = printf("printf    : [%p %p %p]\n", ptr, ptr3, ptr2);
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%p %p %p]\n", ptr, ptr3, ptr2);
	printf("ret = [%d]\n\n", ret);

	ft_printf("@moulitest: %#.x|%#.0x\n", 0, 0);
	printf("@moulitest: %#.x|%#.0x\n", 0, 0);

	ft_printf("@moulitest: %5.x|%5.0x\n", 0, 0);
	printf("@moulitest: %5.x|%5.0x\n", 0, 0);
	

	ft_printf("ft1 : [%-#6o]\n", 2500);
	printf("ft2 : [%-#6o]\n", 2500);
	ft_printf("ft1 : [%5.o|%5.0o]\n", 0, 0);
	printf("ft2 : [%5.o|%5.0o]\n", 0, 0);
	ft_printf("ft1 : [%-+10.5d]\n", 4242);
	printf("ft2 : [%-+10.5d]\n", 4242);
	ft_printf("ft1 : [%.d|%.0d]\n", 42, 43);
	printf("ft2 : [%.d|%.0d]\n", 42, 43);
	ft_printf("ft1 : [%5.d|%5.0d]\n", 0, 0);
	printf("ft2 : [%5.d|%5.0d]\n", 0, 0);

#include <string.h>

	ret = printf("1 %S", L"米");
	ret = ft_printf("2 %S", L"米");
	ret = printf("1 %S", L"我是一只猫。");
	ret = ft_printf("2 %S", L"我是一只猫。");
//	printf("%d\n", ret);
//	ret = ft_printf("2 %S", L"Á±≥");
//	printf("%d\n", ret);
	ret = ft_printf("ft1 : %lD\n", LONG_MAX);
	printf("%d\n", ret);
	ret = printf("ft2 : %lD\n", LONG_MAX);
	printf("%d\n", ret);
	ret = ft_printf("ft3 : %ld\n", LONG_MAX);
	printf("%d\n", ret);*/
/*
	ft_printf("ft1 : %10d\n", 42);
	ft_printf("ft1 : %4d\n", 10000);
	ft_printf("ft1 : %30d\n", 10000);
	ft_printf("ft1 : %10d\n", -42);
	ft_printf("ft1 : %3c\n", 0);
	ft_printf("ft1 : %5p\n", 0);
	ft_printf("ft1 : %-15p\n", 0);
	ft_printf("ft1 : %-13p\n", &strlen);
	ft_printf("ft1 : %-12p\n", &strlen);
	ft_printf("ft1 : %10R\n");

//	wchar_t* wide_str = (wchar_t *)malloc(sizeof(wchar_t) * 256)kkL"œ∑´∑´®®†¥ƒ∫ƒ©∂ßƒ∂≈ç√";
	wchar_t wide_str[] = L"åß∂ƒ©";

	ret = printf("1 %S\n", wide_str);
	printf("%d\n", ret);
	ret = ft_printf("2 %S\n", wide_str);
	printf("%d\n", ret);
	ret = printf("1 %ld\n", LONG_MAX);
	printf("%d\n", ret);
	ret = ft_printf("2 %ld\n", LONG_MAX);
	printf("%d\n\n", ret);
	ret = printf("%#.3o\n", 1);
	printf("%i\n", ret);
	ret = ft_printf("%#.3o\n", 1);
	printf("%i\n", ret);*/

	//printf("%");
	//printf("\n");
//	ft_printf("%-5+d", -42);
//	printf("%-5+d", -42);
//	printf("\n");*/
//	ret = ft_printf("%");
//	printf("%d\n", ret);
	//ret = printf("[%4.1S]\n", L"Jambon");
	//printf("%i\n", ret);
	char *s = "%5+d";
	ret = ft_printf(s, 42);
	printf("\n%i\n", ret);
	ret = printf(s, 42);
	printf("\n%i\n", ret);
	return (0);
}
