#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../ft_printf_test/bonus/ft_printf_bonus.h"

int main(void)
{
	//printf("%-9.+5d\n", 120);
	//ft_printf_bonus("%09.6d\n", 20);
	//printf("%09.6d\n", 20);
	//printf("%09.5-6d\n", 20);
	//printf("%#08.9-9d\n", 0x200);
	//printf("% 90-9d\n", 20);
	//printf("%p\n", '1');
	//printf("%-9.3d\n", 120345);
/*
	ft_printf_bonus("\n------------------------------------------------------------\n");
	ft_printf_bonus("For %%d and %%i: \n");
	ft_printf_bonus("When d = 2: \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("d: %d", 2));
	printf(". Return len: %d\n", printf("d: %d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("9d: %9d", 2));
	printf(". Return len: %d\n", printf("9d: %9d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(".d: %.d", 2));
	printf(". Return len: %d\n", printf(".d: %.d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(".9d: %.9d", 2));
	printf(". Return len: %d\n", printf(".9d: %.9d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("-d: %-d", 2));
	printf(". Return len: %d\n", printf("-d: %-d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("-9d: %-9d", 2));
	printf(". Return len: %d\n", printf("-9d: %-9d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("0d: %0d", 2));
	printf(". Return len: %d\n", printf("0d: %0d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("09d: %09d", 2));
	printf(". Return len: %d\n", printf("09d: %09d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+d: %+d", 2));
	printf(". Return len: %d\n", printf("+d: %+d", 2));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" d: % d", 2));
	printf(". Return len: %d\n", printf(" d: % d", 2));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 20: \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("d: %d", 20));
	printf(". Return len: %d\n", printf("d: %d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("9d: %9d", 20));
	printf(". Return len: %d\n", printf("9d: %9d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(".d: %.d", 20));
	printf(". Return len: %d\n", printf(".d: %.d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(".9d: %.9d", 20));
	printf(". Return len: %d\n", printf(".9d: %.9d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("-d: %-d", 20));
	printf(". Return len: %d\n", printf("-d: %-d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("-9d: %-9d", 20));
	printf(". Return len: %d\n", printf("-9d: %-9d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("0d: %0d", 20));
	printf(". Return len: %d\n", printf("0d: %0d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("09d: %09d", 20));
	printf(". Return len: %d\n", printf("09d: %09d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+d: %+d", 20));
	printf(". Return len: %d\n", printf("+d: %+d", 20));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" d: % d", 20));
	printf(". Return len: %d\n", printf(" d: % d", 20));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 2000000000: \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("d: %d", 2000000000));
	printf(". Return len: %d\n", printf("d: %d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("9d: %9d", 2000000000));
	printf(". Return len: %d\n", printf("9d: %9d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(".d: %.d", 2000000000));
	printf(". Return len: %d\n", printf(".d: %.d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(".9d: %.9d", 2000000000));
	printf(". Return len: %d\n", printf(".9d: %.9d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("-d: %-d", 2000000000));
	printf(". Return len: %d\n", printf("-d: %-d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("-9d: %-9d", 2000000000));
	printf(". Return len: %d\n", printf("-9d: %-9d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("0d: %0d", 2000000000));
	printf(". Return len: %d\n", printf("0d: %0d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("09d: %09d", 2000000000));
	printf(". Return len: %d\n", printf("09d: %09d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+d: %+d", 2000000000));
	printf(". Return len: %d\n", printf("+d: %+d", 2000000000));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" d: % d", 2000000000));
	printf(". Return len: %d\n", printf(" d: % d", 2000000000));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 123456 with '+.*': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+*.*d: %+*.*d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+*.*d: %+*.*d", 15, 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+*.*d: %+*.*d", 5, 15, 123456));
	printf(". Return len: %d\n", printf("+*.*d: %+*.*d", 5, 15, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+*.*d: %*.+++  *d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+*.*d: %*.+++  *d", 15, 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+*.*d: %*.+++  *d", 5, 15, 123456));
	printf(". Return len: %d\n", printf("+*.*d: %*.+++  *d", 5, 15, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 123456 with ' .*': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" *.*d: % *.*d", 15, 5, 123456));
	printf(". Return len: %d\n", printf(" *.*d: % *.*d", 15, 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" *.*d: % *.*d", 5, 15, 123456));
	printf(". Return len: %d\n", printf(" *.*d: % *.*d", 5, 15, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 123456 with '+0*': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+0*d: %+0*d", 15, 123456));
	printf(". Return len: %d\n", printf("+0*d: %+0*d", 15, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+0*d: %+0*d", 5, 123456));
	printf(". Return len: %d\n", printf("+0*d: %+0*d", 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+0*d: %+0*d", 5, 12345));
	printf(". Return len: %d\n", printf("+0*d: %+0*d", 5, 12345));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("*0+++  *d: %*0+++  *d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("*0+++  *d: %*0+++  *d", 15, 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("*0+++  *d: %*0+++  *d", 5, 15, 123456));
	printf(". Return len: %d\n", printf("*0+++  *d: %*0+++  *d", 5, 15, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 123456 with ' 0*': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" 0*d: % 0*d", 15, 123456));
	printf(". Return len: %d\n", printf(" 0*d: % 0*d", 15, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" 0*d: % 0*d", 5, 123456));
	printf(". Return len: %d\n", printf(" 0*d: % 0*d", 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" 0*d: % 0*d", 5, 12345));
	printf(". Return len: %d\n", printf(" 0*d: % 0*d", 5, 12345));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 123456 with '+-*': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+-*d: %+-*d", 15, 123456));
	printf(". Return len: %d\n", printf("+-*d: %+-*d", 15, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+-*d: %+-*d", 5, 123456));
	printf(". Return len: %d\n", printf("+-*d: %+-*d", 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+-*d: %+-*d", 5, 12345));
	printf(". Return len: %d\n", printf("+-*d: %+-*d", 5, 12345));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("*-+++  *d: %*-+++  *d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("*-+++  *d: %*-+++  *d", 15, 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("*-+++  *d: %*-+++  *d", 5, 15, 123456));
	printf(". Return len: %d\n", printf("*-+++  *d: %*-+++  *d", 5, 15, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 123456 with ' -*': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" -*d: % -*d", 15, 123456));
	printf(". Return len: %d\n", printf(" -*d: % -*d", 15, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" -*d: % -*d", 5, 123456));
	printf(". Return len: %d\n", printf(" -*d: % -*d", 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" -*d: % -*d", 5, 12345));
	printf(". Return len: %d\n", printf(" -*d: % -*d", 5, 12345));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When d = 123456 with '+0.*': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+0*.*d: %+0*.*d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+0*.*d: %+0*.*d", 15, 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+08*.*10d: %+08*.*10d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+08*.*10d: %+08*.*10d", 15, 5, 123456));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("+08*.*d: %+08*.*d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+08*.*d: %+08*.*d", 15, 5, 123456));

	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf(". Return len: %d\n", printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

	
	ft_printf_bonus("%+05.9d\n", 123456);
	printf("%+05.9d\n", 123456);
	ft_printf_bonus("%+015.5d\n", 123456);
	printf("%+015.5d\n", 123456);
	ft_printf_bonus("%+-5.9d\n", 123456);
	printf("%+-5.9d\n", 123456);
	ft_printf_bonus("%+-15-.5d\n", 123456);
	printf("%+-15-.5d\n", 123456);


	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When c = 'c': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("10c: %10c", 'c'));
	printf(". Return len: %d\n", printf("10c: %10c", 'c'));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("010c: %010c", 'c'));
	printf(". Return len: %d\n", printf("010c: %010c", 'c'));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("-10c: %-10c", 'c'));
	printf(". Return len: %d\n", printf("-10c: %-10c", 'c'));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" %-3c", '0' - 256));
	printf(". Return len: %d\n", printf(" %-3c", '0' - 256));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("%-4c ", '0' + 256));
	printf(". Return len: %d\n", printf("%-4c ", '0' + 256));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" %-1c %-2c %-3c ", 0, '1', '2'));
	printf(". Return len: %d\n", printf(" %-1c %-2c %-3c ", 0, '1', '2'));

	printf("\n-----------------------------------------------------\n");
	ft_printf_bonus("When s = 'abcdef': \n");
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("%1s", ""));
	printf(". Return len: %d\n", printf("%1s", ""));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("10c: %10s", "abcdef"));
	printf(". Return len: %d\n", printf("10c: %10s", "abcdef"));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("-10c: %-10s", "abcdef"));
	printf(". Return len: %d\n", printf("-10c: %-10s", "abcdef"));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus("010c: %010s", "abcdef"));
	printf(". Return len: %d\n", printf("010c: %010s", "abcdef"));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(".10c: %.10s", "abcdef"));
	printf(". Return len: %d\n", printf(".10c: %.10s", "abcdef"));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(".1c: %.1s", "abcdef"));
	printf(". Return len: %d\n", printf(".1c: %.1s", "abcdef"));
	ft_printf_bonus(". Return len(ft): %d\n", ft_printf_bonus(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 "));
	printf(". Return len: %d\n", printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 "));

	printf("%p\n", "a");
	printf("%12p\n", "a");
	printf("%-12p\n", "a");
	printf("%012p\n", "a");
	printf("%.12p\n", "a");
	printf("%015.12p\n", "a");
	printf("%-15.8p\n", "a");
	printf("%15.8p\n", "a");
	printf("%15-12.8p\n", "a");
*/

	unsigned long long address;

	address = (unsigned long long)"abcde";
	printf("%llu\n", address);

	return (0);
}
