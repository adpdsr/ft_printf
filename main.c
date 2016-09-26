//
// HEADER
//

#include "ft_printf.h"

int			main(void)
{
	char *ptr;

	ptr = NULL;
	printf("\ntests : CHAR\n\n");
	printf("printf    = [%2c %c %-6c %2c %c %%]\n", 'a', 'b', 'c', 'd', ' ');
	ft_printf("ft_printf = [%2c %c %-6c %2c %c %%]\n\n", 'a', 'b', 'c', 'd', ' ');

	printf("\ntests : STRING\n\n");
	printf("printf    = [%2s %s %-6s %s]\n", "a", "salut", "yo", ptr);
	ft_printf("ft_printf = [%2s %s %-6s %s]\n\n", "a", "salut", "yo", ptr);
	//		printf("printf    = [%s %d %c %i %x %X]\n", "test1", 2, '3', 4, 12, 13);
	//		ft_printf("ft_printf = [%s %d %c %i %x %X]\n\n", "test1", 2, '3', 4, 12, 13);

	//		printf("printf    = [%10s%3.1d %2c %2.1d %2.1x %4.1X]\n", "test1", 20, '3', 123451212, 50, 60);
	//		ft_printf("ft_printf = [%10s%3.1d %2c %2.1d %2.1x %4.1X]\n", "test1", 20, '3', 123451212, 50, 60);

	ft_printf("ft_printf = [test0 %+8d %+i %20ld]\n", -13200, 12, 20202020202020);	
	printf("printf    = [test0 %+8d %+i %20ld]\n", -13200, 12, 20202020202020);	

	ft_printf("ft_printf = [test %c %-12.5s]\n", 'a', "test1 salut");	
	printf("printf    = [test %c %-12.5s]\n", 'a', "test1 salut");	

	ft_printf("ft_printf = [test %20x %2X]\n", 123456789, -321654987);
	printf("printf    = [test %20x %2X]\n", 123456789, -321654987);
	return (0);
}
