/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:45:30 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/10/11 21:15:59 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <wchar.h>

int			main(void)
{	
	int		ret;
	char	*ptr;	
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
	
	printf("--- WSTR ---------------------------------\n\n");
//	printf("printf    : [%30ls %.5S]\n", L"æ«€¶ŧ←↓→øþ", L"@ßðđŋħłµł»¢“”n");
	ft_printf("ft_printf : [%-30ls %.5S]\n\n", L"æ«€¶ŧ←↓→øþ", L"@ßðđŋħłµł»¢“”n");
		
	printf("--- PTR ----------------------------------\n\n");
	
	ret = printf("printf    : [%p %p %p]\n", ptr, ptr3, ptr2);
	printf("ret = [%d]\n", ret);
	ret = ft_printf("ft_printf : [%p %p %p]\n", ptr, ptr3, ptr2);
	printf("ret = [%d]\n\n", ret);

	ft_printf("@moulitest: %#.x|%#.0x\n", 0, 0);
	printf("@moulitest: %#.x|%#.0x\n", 0, 0);

	ft_printf("@moulitest: %5.x|%5.0x\n", 0, 0);
	printf("@moulitest: %5.x|%5.0x\n", 0, 0);
	
	return (0);
}
