//
// HEADER
//

#include <stdio.h> // test
#include <stdarg.h>

static char	*ft_strchr(const char *str, int c)
{
	char	*strchr;

	strchr = NULL;
	while (*str != '\0')
	{
		if (*str == c)
		{
			strchr = (char *)str;
			return (strchr);
		}
		str++;
	}
	return (NULL);
}

static void	handle_str(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	printf("str    = [%s]\n", str);	
}

static void	handle_int(va_list arg)
{
	int		res;

	res = va_arg(arg, int);
	printf("res    = [%i]\n", res);	
}

static int	parse(va_list arg, const char *format)
{
	char	*str;

	str = ft_strchr(format, '%');
	printf("format = [%s]\n", format);
	printf("strchr = [%s]\n", str);
	if (!*(str + 1))
		return (1);
	else if (*(str + 1) == 's')
		handle_str(arg);
	else if (*(str + 1) == 'i')
		handle_int(arg);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int	ret;
	va_list	arg;

	va_start(arg, format);
	ret = parse(arg, format);
	va_end(arg);
	return (ret);
}

int			main(void)
{
	ft_printf("test1%stest3", "test2");
	ft_printf("test1%itest3", 2);
	return (0);
}
