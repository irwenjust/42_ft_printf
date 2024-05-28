#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../ft_printf/bonus/ft_printf_bonus.h"

int main(void)
{
	ft_printf("\n------------------------------------------------------------\n");
	ft_printf("For %%d and %%i: \n");
	ft_printf("When d = 2: \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("d: %d", 2));
	printf(". Return len: %d\n", printf("d: %d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf("9d: %9d", 2));
	printf(". Return len: %d\n", printf("9d: %9d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf(".d: %.d", 2));
	printf(". Return len: %d\n", printf(".d: %.d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf(".9d: %.9d", 2));
	printf(". Return len: %d\n", printf(".9d: %.9d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf("-d: %-d", 2));
	printf(". Return len: %d\n", printf("-d: %-d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf("-9d: %-9d", 2));
	printf(". Return len: %d\n", printf("-9d: %-9d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf("0d: %0d", 2));
	printf(". Return len: %d\n", printf("0d: %0d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf("09d: %09d", 2));
	printf(". Return len: %d\n", printf("09d: %09d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf("+d: %+d", 2));
	printf(". Return len: %d\n", printf("+d: %+d", 2));
	ft_printf(". Return len(ft): %d\n", ft_printf(" d: % d", 2));
	printf(". Return len: %d\n", printf(" d: % d", 2));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 20: \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("d: %d", 20));
	printf(". Return len: %d\n", printf("d: %d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf("9d: %9d", 20));
	printf(". Return len: %d\n", printf("9d: %9d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf(".d: %.d", 20));
	printf(". Return len: %d\n", printf(".d: %.d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf(".9d: %.9d", 20));
	printf(". Return len: %d\n", printf(".9d: %.9d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf("-d: %-d", 20));
	printf(". Return len: %d\n", printf("-d: %-d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf("-9d: %-9d", 20));
	printf(". Return len: %d\n", printf("-9d: %-9d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf("0d: %0d", 20));
	printf(". Return len: %d\n", printf("0d: %0d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf("09d: %09d", 20));
	printf(". Return len: %d\n", printf("09d: %09d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf("+d: %+d", 20));
	printf(". Return len: %d\n", printf("+d: %+d", 20));
	ft_printf(". Return len(ft): %d\n", ft_printf(" d: % d", 20));
	printf(". Return len: %d\n", printf(" d: % d", 20));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 2000000000: \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("d: %d", 2000000000));
	printf(". Return len: %d\n", printf("d: %d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf("9d: %9d", 2000000000));
	printf(". Return len: %d\n", printf("9d: %9d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf(".d: %.d", 2000000000));
	printf(". Return len: %d\n", printf(".d: %.d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf(".9d: %.9d", 2000000000));
	printf(". Return len: %d\n", printf(".9d: %.9d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf("-d: %-d", 2000000000));
	printf(". Return len: %d\n", printf("-d: %-d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf("-9d: %-9d", 2000000000));
	printf(". Return len: %d\n", printf("-9d: %-9d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf("0d: %0d", 2000000000));
	printf(". Return len: %d\n", printf("0d: %0d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf("09d: %09d", 2000000000));
	printf(". Return len: %d\n", printf("09d: %09d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf("+d: %+d", 2000000000));
	printf(". Return len: %d\n", printf("+d: %+d", 2000000000));
	ft_printf(". Return len(ft): %d\n", ft_printf(" d: % d", 2000000000));
	printf(". Return len: %d\n", printf(" d: % d", 2000000000));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 123456 with '+.*': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("+*.*d: %+*.*d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+*.*d: %+*.*d", 15, 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+*.*d: %+*.*d", 5, 15, 123456));
	printf(". Return len: %d\n", printf("+*.*d: %+*.*d", 5, 15, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+*.*d: %*.+++  *d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+*.*d: %*.+++  *d", 15, 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+*.*d: %*.+++  *d", 5, 15, 123456));
	printf(". Return len: %d\n", printf("+*.*d: %*.+++  *d", 5, 15, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 123456 with ' .*': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf(" *.*d: % *.*d", 15, 5, 123456));
	printf(". Return len: %d\n", printf(" *.*d: % *.*d", 15, 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf(" *.*d: % *.*d", 5, 15, 123456));
	printf(". Return len: %d\n", printf(" *.*d: % *.*d", 5, 15, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 123456 with '+0*': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("+0*d: %+0*d", 15, 123456));
	printf(". Return len: %d\n", printf("+0*d: %+0*d", 15, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+0*d: %+0*d", 5, 123456));
	printf(". Return len: %d\n", printf("+0*d: %+0*d", 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+0*d: %+0*d", 5, 12345));
	printf(". Return len: %d\n", printf("+0*d: %+0*d", 5, 12345));
	ft_printf(". Return len(ft): %d\n", ft_printf("*0+++  *d: %*0+++  *d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("*0+++  *d: %*0+++  *d", 15, 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("*0+++  *d: %*0+++  *d", 5, 15, 123456));
	printf(". Return len: %d\n", printf("*0+++  *d: %*0+++  *d", 5, 15, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 123456 with ' 0*': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf(" 0*d: % 0*d", 15, 123456));
	printf(". Return len: %d\n", printf(" 0*d: % 0*d", 15, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf(" 0*d: % 0*d", 5, 123456));
	printf(". Return len: %d\n", printf(" 0*d: % 0*d", 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf(" 0*d: % 0*d", 5, 12345));
	printf(". Return len: %d\n", printf(" 0*d: % 0*d", 5, 12345));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 123456 with '+-*': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("+-*d: %+-*d", 15, 123456));
	printf(". Return len: %d\n", printf("+-*d: %+-*d", 15, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+-*d: %+-*d", 5, 123456));
	printf(". Return len: %d\n", printf("+-*d: %+-*d", 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+-*d: %+-*d", 5, 12345));
	printf(". Return len: %d\n", printf("+-*d: %+-*d", 5, 12345));
	ft_printf(". Return len(ft): %d\n", ft_printf("*-+++  *d: %*-+++  *d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("*-+++  *d: %*-+++  *d", 15, 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("*-+++  *d: %*-+++  *d", 5, 15, 123456));
	printf(". Return len: %d\n", printf("*-+++  *d: %*-+++  *d", 5, 15, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 123456 with ' -*': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf(" -*d: % -*d", 15, 123456));
	printf(". Return len: %d\n", printf(" -*d: % -*d", 15, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf(" -*d: % -*d", 5, 123456));
	printf(". Return len: %d\n", printf(" -*d: % -*d", 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf(" -*d: % -*d", 5, 12345));
	printf(". Return len: %d\n", printf(" -*d: % -*d", 5, 12345));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = 123456 with '+0.*': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("+0*.*d: %+0*.*d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+0*.*d: %+0*.*d", 15, 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+08*.*10d: %+08*.*10d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+08*.*10d: %+08*.*10d", 15, 5, 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("+08*.*d: %+08*.*d", 15, 5, 123456));
	printf(". Return len: %d\n", printf("+08*.*d: %+08*.*d", 15, 5, 123456));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When d = fran and few wierd test: \n");
	ft_printf(". Return len(ft): %d\n", ft_printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf(". Return len: %d\n", printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf(". Return len(ft): %d\n", ft_printf("%+05.9d", 123456));
	printf(". Return len: %d\n", printf("%+05.9d", 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("%+015.5d", 123456));
	printf(". Return len: %d\n", printf("%+015.5d", 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("%+-5.9d", 123456));
	printf(". Return len: %d\n", printf("%+-5.9d", 123456));
	ft_printf(". Return len(ft): %d\n", ft_printf("%+-15-.5d", 123456));
	printf(". Return len: %d\n", printf("%+-15-.5d", 123456));


	printf("\n-----------------------------------------------------\n");
	ft_printf("When c = 'c': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("10c: %10c", 'c'));
	printf(". Return len: %d\n", printf("10c: %10c", 'c'));
	ft_printf(". Return len(ft): %d\n", ft_printf("010c: %010c", 'c'));
	printf(". Return len: %d\n", printf("010c: %010c", 'c'));
	ft_printf(". Return len(ft): %d\n", ft_printf("-10c: %-10c", 'c'));
	printf(". Return len: %d\n", printf("-10c: %-10c", 'c'));
	ft_printf(". Return len(ft): %d\n", ft_printf(" %-3c", '0' - 256));
	printf(". Return len: %d\n", printf(" %-3c", '0' - 256));
	ft_printf(". Return len(ft): %d\n", ft_printf("%-4c ", '0' + 256));
	printf(". Return len: %d\n", printf("%-4c ", '0' + 256));
	ft_printf(". Return len(ft): %d\n", ft_printf(" %-1c %-2c %-3c ", 0, '1', '2'));
	printf(". Return len: %d\n", printf(" %-1c %-2c %-3c ", 0, '1', '2'));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When s = 'abcdef': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("%1s", ""));
	printf(". Return len: %d\n", printf("%1s", ""));
	ft_printf(". Return len(ft): %d\n", ft_printf("10s: %10s", "abcdef"));
	printf(". Return len: %d\n", printf("10s: %10s", "abcdef"));
	ft_printf(". Return len(ft): %d\n", ft_printf("-10s: %-10s", "abcdef"));
	printf(". Return len: %d\n", printf("-10s: %-10s", "abcdef"));
	ft_printf(". Return len(ft): %d\n", ft_printf("010s: %010s", "abcdef"));
	printf(". Return len: %d\n", printf("010s: %010s", "abcdef"));
	ft_printf(". Return len(ft): %d\n", ft_printf(".10s: %.10s", "abcdef"));
	printf(". Return len: %d\n", printf(".10s: %.10s", "abcdef"));
	ft_printf(". Return len(ft): %d\n", ft_printf(".1s: %.1s", "abcdef"));
	printf(". Return len: %d\n", printf(".1s: %.1s", "abcdef"));
	ft_printf(". Return len(ft): %d\n", ft_printf("20.-10s: %20.-10s", "abcdef"));
	printf(". Return len: %d\n", printf("20.-10s: %20.-10s", "abcdef"));
	ft_printf(". Return len(ft): %d\n", ft_printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 "));
	printf(". Return len: %d\n", printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 "));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When p = 0: \n");
	ft_printf(". Return len: %d\n", ft_printf(".p: %.p", 0));
	printf(". Return len: %d\n", printf(".p: %.p", 0));
	ft_printf(". Return len: %d\n", ft_printf("0p: %0p", 0));
	printf(". Return len: %d\n", printf("0p: %0p", 0));
	ft_printf(". Return len: %d\n", ft_printf("-p: %-p", 0));
	printf(". Return len: %d\n", printf("-p: %-p", 0));

	ft_printf(". Return len: %d\n", ft_printf(".0p: %.0p", 0));
	printf(". Return len: %d\n", printf(".0p: %.0p", 0));
	ft_printf(". Return len: %d\n", ft_printf("-.p: %-.p", 0));
	printf(". Return len: %d\n", printf("-.p: %-.p", 0));
	ft_printf(". Return len: %d\n", ft_printf("-0p: %-0p", 0));
	printf(". Return len: %d\n", printf("-0p: %-0p", 0));
	ft_printf(". Return len: %d\n", ft_printf("-.0p: %-.0p", 0));
	printf(". Return len: %d\n", printf("-.0p: %-.0p", 0));
	ft_printf(". Return len: %d\n", ft_printf(" %p %p ", 0, 0));
	printf(". Return len: %d\n", printf(" %p %p ", 0, 0));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When p = a: \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("p: %p", 'a'));
	printf(". Return len: %d\n", printf("p: %p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("12p: %12p", 'a'));
	printf(". Return len: %d\n", printf("12p: %12p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("-12p: %-12p", 'a'));
	printf(". Return len: %d\n", printf("-12p: %-12p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("012p: %012p", 'a'));
	printf(". Return len: %d\n", printf("012p: %012p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("015.12p: %015.12p", 'a'));
	printf(". Return len: %d\n", printf("015.12p: %015.12p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("015.8p: %015.8p", 'a'));
	printf(". Return len: %d\n", printf("015.8p: %015.8p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("-15.8p: %-15.8p", 'a'));
	printf(". Return len: %d\n", printf("-15.8p: %-15.8p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("15-.8p: %15-.8p", 'a'));
	printf(". Return len: %d\n", printf("15-.8p: %15-.8p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("-15.12p: %-15.12p", 'a'));
	printf(". Return len: %d\n", printf("-15.12p: %-15.12p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf(".p: %.p", 'a'));
	printf(". Return len: %d\n", printf(".p: %.p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("0p: %0p", 'a'));
	printf(". Return len: %d\n", printf("0p: %0p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("-p: %-p", 'a'));
	printf(". Return len: %d\n", printf("-p: %-p", 'a'));
	ft_printf(". Return len(ft): %d\n", ft_printf("15-12.8p: %15-12.8p", 'a'));
	printf(". Return len: %d\n", printf("15-12.8p: %15-12.8p", 'a'));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When p = 'a': \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("p: %p", "a"));
	printf(". Return len: %d\n", printf("p: %p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("12p: %12p", "a"));
	printf(". Return len: %d\n", printf("12p: %12p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("-12p: %-12p", "a"));
	printf(". Return len: %d\n", printf("-12p: %-12p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("012p: %012p", "a"));
	printf(". Return len: %d\n", printf("012p: %012p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("015.12p: %015.12p", "a"));
	printf(". Return len: %d\n", printf("015.12p: %015.12p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("015.8p: %015.8p", "a"));
	printf(". Return len: %d\n", printf("015.8p: %015.8p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("-15.8p: %-15.8p", "a"));
	printf(". Return len: %d\n", printf("-15.8p: %-15.8p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("15-.8p: %15-.8p", "a"));
	printf(". Return len: %d\n", printf("15-.8p: %15-.8p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("-15.12p: %-15.12p", "a"));
	printf(". Return len: %d\n", printf("-15.12p: %-15.12p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("15.12p: %15.12p", "a"));
	printf(". Return len: %d\n", printf("15.12p: %15.12p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("15.8p: %15.8p", "a"));
	printf(". Return len: %d\n", printf("15.8p: %15.8p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("8.15p: %8.15p", "a"));
	printf(". Return len: %d\n", printf("8.15p: %8.15p", "a"));
	ft_printf(". Return len(ft): %d\n", ft_printf("15-12.8p: %15-12.8p", "a"));
	printf(". Return len: %d\n", printf("15-12.8p: %15-12.8p", "a"));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When p = fran: \n");
	ft_printf(". Return len(ft): %d\n", ft_printf(" %-1p %-2p ", 0, 0));
	printf(". Return len: %d\n", printf(" %-1p %-2p ", 0, 0));
	ft_printf(". Return len(ft): %d\n", ft_printf(" %-9p %-10p ", LONG_MIN, LONG_MAX));
	printf(". Return len: %d\n", printf(" %-9p %-10p ", LONG_MIN, LONG_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf(" %-11p %-12p ", INT_MIN, INT_MAX));
	printf(". Return len: %d\n", printf(" %-11p %-12p ", INT_MIN, INT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));
	printf(". Return len: %d\n", printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));
	
	//ft_printf("ft_s: %.s\n", "12345");
	//printf("n: %.s\n", "12345");
	//ft_printf("ft_n: %.\n", "12345");
	//printf("n: %.\n", "12345");
	//printf("\n%.d\n", 12345);

	//ft_printf("%.s, %.s, %.s, %.s", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	//printf("wtf: %.s, %.s, %.s, %.s\n", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	//ft_printf("wtf: %.s, %.s, %.s, %.s\n", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	//printf("w: %7.s\n", "wtf");

	// ft_printf(". Return len(ft): %d\n", ft_printf("%#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	// printf(". Return len: %d\n", printf("%#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	// ft_printf(". Return len(ft): %d\n", ft_printf("%#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	// printf(". Return len: %d\n", printf("%#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));

	printf("\n-----------------------------------------------------\n");
	ft_printf("When p = fran(error): \n");
	ft_printf(". Return len(ft): %d\n", ft_printf("%#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x, %#x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#1x, %#1x, %#1x, %#1x, %#1x, %#1x, %#1x, %#1x, %#1x, %#1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#1x, %#1x, %#1x, %#1x, %#1x, %#1x, %#1x, %#1x, %#1x, %#1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#5x, %#5x, %#5x, %#5x, %#5x, %#5x, %#5x, %#5x, %#5x, %#5x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#5x, %#5x, %#5x, %#5x, %#5x, %#5x, %#5x, %#5x, %#5x, %#5x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#10x, %#10x, %#10x, %#10x, %#10x, %#10x, %#10x, %#10x, %#10x, %#10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#10x, %#10x, %#10x, %#10x, %#10x, %#10x, %#10x, %#10x, %#10x, %#10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x, %#100x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x, %#.0x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x, %#.1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x, %#.5x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x, %#.10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x, %#.100x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x, %#1.x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x, %#1.1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x, %#1.5x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x, %#1.10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x, %0#10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf(". Return len(ft): %d\n", ft_printf("%0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf(". Return len: %d\n", printf("%0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));

	//ft_printf(". Return len(ft): %d\n", ft_printf(" %u ", 0));
	//printf(". Return len: %d\n", printf(" %u ", 0));
	//ft_printf(". Return len(ft): %d\n", ft_printf("%-7d", 33));
	//printf(". Return len: %d\n", printf("%-7d", 33));
	//ft_printf(". Return len(ft): %d\n", ft_printf("%01.10d", 0));
	//printf(". Return len: %d\n", printf("%01.10d", 0));

	//ft_printf(". Return len: %d\n", ft_printf("%-2147483648d", 1000000000));
	//printf(". Return len: %d\n", printf("%-2147483648d", 1000000000));
	//printf("%d", 100000000000);
	
	
	return (0);
}
