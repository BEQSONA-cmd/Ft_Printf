#include "Bonus/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = printf("%10s", "Hello");
	printf("\n");
	j = ft_printf("%10s", "Hello");
	printf("\n");
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%10p", "");
	j = ft_printf("%10p", "");
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%10d", 42);
	j = ft_printf("%10d", 42);
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%s", "Hello");
	j = ft_printf("%s", "Hello");
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%s %%", "hello");
	j = ft_printf("%s %%", "hello");
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%s %s", "Hello", "World");
	j = ft_printf("%s %s", "Hello", "World");
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%s %d", "Hello my friends", -41231);
	j = ft_printf("%s %d", "Hello my friends", -41231);
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%s %d %x", "Hello", 52, 12344);
	j = ft_printf("%s %d %x", "Hello", 52, 12344);
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%s %X", "HELLO my friends", 0);
	j = ft_printf("%s %X", "HELLO my friends", 0);
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%s %X %x", "HELLO my friends", 0, 0);
	j = ft_printf("%s %X %x", "HELLO my friends", 0, 0);
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%X %x %s", 0, 0, "HELLO my friendsssssadas");
	j = ft_printf("%X %x %s", 0, 0, "HELLO my friendsssssadas");
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%d %X %s", 25435, 2112333, "HELLO friendsss");
	j = ft_printf("%d %X %s", 25435, 2112333, "HELLO friendsss");
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%d %p %s", 25435, (void *)0x12344444, "HELLO friendsss");
	j = ft_printf("%d %p %s", 25435, (void *)0x12344444, "HELLO friendsss");
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
	i = printf("%s", NULL);
	j = ft_printf("%s", NULL);
	printf("\n");
	printf("orig:%d\n", i);
	printf("mine:%d\n", j);
	printf("\n");
}
