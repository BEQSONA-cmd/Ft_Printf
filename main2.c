#include "Bonus/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("Field minimum width:\n");
	printf("orig:|%10s|\n", "Hello");
	ft_printf("mine:|%10s|\n", "Hello");
	printf("\n");

	printf("Left alignment with field minimum width:\n");
	printf("orig: |%-10s|\n", "Hello");
	ft_printf("mine: |%-10s|\n", "Hello");
	printf("\n");

	printf("Zero padding with field minimum width:\n");
	printf("orig: |%010s|\n", "Hello");
	ft_printf("mine: |%010s|\n", "Hello");
	printf("\n");

	printf("Zero padding with field minimum width:\n");
	printf("orig: |%-010s|\n", "Hello");
	ft_printf("mine: |%-010s|\n", "Hello");
	printf("\n");

	printf("Precision:\n");
	printf("orig: |%.3s|\n", "Hello");
	ft_printf("mine: |%.3s|\n", "Hello");
	printf("\n");

	printf("Hash flag (for hexadecimal):\n");
	printf("orig: %#x\n", 555);
	ft_printf("mine: %#x\n", 555);
	printf("orig: %#x\n", -14);
	ft_printf("mine: %#x\n", -14);
	printf("orig: %#x\n", 0);
	ft_printf("mine: %#x\n", 0);
	printf("orig: %#X\n", 555);
	ft_printf("mine: %#X\n", 555);
	printf("orig: %#X\n", -14);
	ft_printf("mine: %#X\n", -14);
	printf("orig: %#X\n", 0);
	ft_printf("mine: %#X\n", 0);
	printf("\n");

	printf("Plus flag (for signed numbers):\n");
	printf("orig: %+d\n", 42);
	ft_printf("mine: %+d\n", 42);
	printf("orig: %+d\n", -42);
	ft_printf("mine: %+d\n", -42);
	printf("\n");

	printf("Space flag (for signed numbers):\n");
	printf("orig: % d\n", 42);
	ft_printf("mine: % d\n", 42);
	printf("orig: % d\n", -42);
	ft_printf("mine: % d\n", -42);
	printf("\n");

	printf("Zero flag (for signed numbers):\n");
	printf("orig: %0d\n", 42);
	ft_printf("mine: %0d\n", 42);
	printf("orig: %0d\n", -42);
	ft_printf("mine: %0d\n", -42);
	printf("\n");

	printf("Precision and field minimum width:\n");
	printf("orig: |%10.3s|\n", "Hello");
	ft_printf("mine: |%10.3s|\n", "Hello");
	printf("\n");

	printf("Precision and field minimum width with left alignment:\n");
	printf("orig: |%-10.3s|\n", "Hello");
	ft_printf("mine: |%-10.3s|\n", "Hello");
	printf("\n");

	printf("Precision and field minimum width with zero padding:\n");
	printf("orig: |%010.3s|\n", "Hello");
	ft_printf("mine: |%010.3s|\n", "Hello");
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%-010.3s|\n", "Hello");
	ft_printf("mine: |%-010.3s|\n", "Hello");
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%-010.3s|\n", "Hello");
	ft_printf("mine: |%-010.3s|\n", "Hello");
	printf("\n");

	printf("Precision and field minimum width:\n");
	printf("orig: |%10.3c|\n", 'D');
	ft_printf("mine: |%10.3c|\n", 'D');
	printf("\n");

	printf("Precision and field minimum width with left alignment:\n");
	printf("orig: |%-10.3c|\n", 'D');
	ft_printf("mine: |%-10.3c|\n", 'D');
	printf("\n");

	printf("Precision and field minimum width with zero padding:\n");
	printf("orig: |%010.3c|\n", 'D');
	ft_printf("mine: |%010.3c|\n", 'D');
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%-010.3c|\n", 'D');
	ft_printf("mine: |%-010.3c|\n", 'D');
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%-010.3c|\n", 'D');
	ft_printf("mine: |%-010.3c|\n", 'D');
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%-010.3d|\n", 432222);
	ft_printf("mine: |%-010.3d|\n", 432222);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%+010.3d|\n", 432222);
	ft_printf("mine: |%+010.3d|\n", 432222);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%+-10.3d|\n", 432222);
	ft_printf("mine: |%+-10.3d|\n", 432222);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%0c|\n", 43);
	ft_printf("mine: |%0c|\n", 43);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%0c|\n", 43);
	ft_printf("mine: |%0c|\n", 43);
	printf("\n");

	printf("Precision and field minimum width:\n");
	printf("orig: |%10d|\n", 43);
	ft_printf("mine: |%10d|\n", 43);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%-010.3x|\n", 432222);
	ft_printf("mine: |%-010.3x|\n", 432222);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%+010.3x|\n", 432222);
	ft_printf("mine: |%+010.3x|\n", 432222);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%+-10.3x|\n", 432222);
	ft_printf("mine: |%+-10.3x|\n", 432222);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%0x|\n", 43);
	ft_printf("mine: |%0x|\n", 43);
	printf("\n");

	printf("Precision and field minimum width with zero padding and left alignment:\n");
	printf("orig: |%0X|\n", 43);
	ft_printf("mine: |%0X|\n", 43);
	printf("\n");

	printf("Precision and field minimum width:\n");
	printf("orig: |%10x|\n", 14);
	ft_printf("mine: |%10x|\n", 14);
	printf("\n");

	printf("Precision and field minimum width:\n");
	printf("orig: |%-10x|\n", 14);
	ft_printf("mine: |%-10x|\n", 14);
	printf("\n");

	printf("Precision and field minimum width:\n");
	printf("orig: |%10X|\n", 14);
	ft_printf("mine: |%10X|\n", 14);
	printf("\n");

	printf("Precision and field minimum width:\n");
	printf("orig: |%-10X|\n", 14);
	ft_printf("mine: |%-10X|\n", 14);
	printf("\n");

	printf("Pointer address:\n");
	int num = 42;
	printf("orig: |%p|\n", (void *)&num);
	ft_printf("mine: |%p|\n", (void *)&num);
	printf("\n");

	printf("Unsigned integer:\n");
	unsigned int u_num = 3000000000;
	printf("orig: |%u|\n", u_num);
	ft_printf("mine: |%u|\n", u_num);
	printf("\n");

	printf("Precision and field minimum width:\n");
	printf("orig: |%10u|\n", 43);
	ft_printf("mine: |%10u|\n", 43);
	printf("\n");

	printf("Unsigned integer with field width:\n");
	printf("orig: |%15u|\n", u_num);
	ft_printf("mine: |%15u|\n", u_num);
	printf("\n");

	printf("Pointer address:\n");
	num = 42;
	printf("orig: |%-15p|\n", (void *)&num);
	ft_printf("mine: |%-15p|\n", (void *)&num);
	printf("\n");

	printf("Pointer address:\n");
	num = 42;
	printf("orig: |%15p|\n", (void *)&num);
	ft_printf("mine: |%15p|\n", (void *)&num);
	printf("\n");

	return (0);
}