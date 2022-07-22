#include <stdio.h>
#include "../../ft_printf/includes/libftprintf.h"

// int	main()
// {
// 	// char *p = "foo";
// 	// int ret_original;
// 	// int ret_ft;
// 	// printf("printf between quotes : ");
// 	// ret_original = printf("one string\n");
// 	// ft_printf("ft_printf between quotes : ");
// 	// ret_ft = ft_printf("one string\n");
// 	// printf("printf return value : %d\n", ret_original);
// 	// printf("ft_printf return value : %d\n", ret_ft);
// 	// printf("printf with specifier s : ");
// 	// ret_original = printf("%s\n", "one string");
// 	// printf("printf return value : %d\n", ret_original);
// 	// ft_printf("ft_printf with specifier s : ");
// 	// ret_ft = ft_printf("%s\n", "one string");
// 	// printf("ft_printf return value : %d\n", ret_ft);
// 	// ret_original = printf("%-60s|\n", "a string");
// 	// printf("printf return value : %d\n", ret_original);
// 	// ret_ft = ft_printf("%-60s|\n", "a string");
// 	// printf("ft_printf return value : %d\n", ret_ft);
// 	// printf("printf with specifier s and flag - and . : ");
// 	// ret_original = printf("%-6.s|\n", "a string");
// 	// printf("printf return value : %d\n", ret_original);	
// 	// ft_printf("ft_printf with specifier s and flag - and . : ");
// 	// ret_ft = ft_printf("%-6.s|\n", "a string");
// 	// printf("ft_printf return value : %d\n", ret_ft);
// 	// printf("%.0s|\n", "a string");
// 	// ft_printf("%.0s|\n", "a string");
// 	// printf("%32s\n", "abc");
// 	// ft_printf("%32s\n", "abc");

// // 	/*test null pointer in string*/
// // 	ret_original = printf("%s\n", p);
// // 	printf("printf null pointer return value : %d\n", ret_original);
// // 	ret_ft = ft_printf("%s\n", p);
// // 	printf("ft_printf null pointer return value : %d\n", ret_ft);
// // 	printf("%d\n", printf(" NULL %s NULL \n", NULL));
// // 	printf("%d\n", ft_printf(" NULL %s NULL \n", NULL));
	
// // 	/*tests precision s*/
// // 	printf("%.3s\n", "hello");
// // 	ft_printf("%.3s\n", "hello");
// // 	printf("%-3.1s\n", NULL);
// // 	ft_printf("%-3.1s\n", NULL);
// // 	printf("%d\n", printf("%32s|\n", NULL));
// // 	printf("%d\n", ft_printf("%32s|\n", NULL));
// // 	printf("%8.5s|\n   ", "-");
// // 	ft_printf("%8.5s|\n   ", "-");
// // 	ft_printf("%.1s|\n", "-");
// // 	printf("%d\n", printf("%.1s|\n ", "-"));
// // 	printf("%d\n", ft_printf("%.1s|\n ", "-"));
// // 	printf(" %.2s %.1s|\n ", "", "-");
// // 	ft_printf(" %.2s %.1s|\n ", "", "-");
// // 	printf(" %.3s %.2s \n", " - ", "");
// // 	ft_printf(" %.3s %.2s \n", " - ", "");
// // 	printf(" %.1s %.2s %.3s %.4s \n", " - ", "", "4", "");
// // 	ft_printf(" %.1s %.2s %.3s %.4s \n", " - ", "", "4", "");
// // 	printf("%d\n", printf(" %.2s %.3s %.4s %.5s %.1s \n", " - ", "", "4", "", "2 "));
// // 	printf ("%d\n", ft_printf(" %.2s %.3s %.4s %.5s %.1s \n", " - ", "", "4", "", "2 "));
// // 	printf("%d\n", printf(" %.1s|\n", ""));
// // 	printf("%d\n", ft_printf(" %.1s|\n", ""));
// // 	printf("%d\n", printf(" %.s \n", ""));
// // 	printf("%d\n", ft_printf(" %.s \n", ""));
// // 	printf("%d\n", printf(" %.s |", "-"));
// // 	printf("%d\n", ft_printf(" %.s |", "-"));
// // 	printf("%d\n", printf(" %.2s %.1s ", "", "-"));
// // 	printf("%d\n", ft_printf(" %.2s %.1s ", "", "-"));
// // 	printf("%d\n", printf(" %.3s %.2s ", " - ", ""));
// // 	printf("%d\n", ft_printf(" %.3s %.2s ", " - ", ""));
// // 	ft_printf(" %.3s %.2s |\n", " - ", "");
// // 	ft_printf(" %.3s %.2s |\n", " - ", "");
// // 	printf("%d\n", printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));
// // 	printf("%d\n", ft_printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));
// // 	printf("%d\n", printf(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
// // 	printf("%d\n", ft_printf(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
	
// // 	/*test char*/
// // 	printf("printf : ");
// // 	ret_original = printf("char : %c\n", 'a');
// // 	printf("printf return value : %d\n", ret_original);
// // 	ft_printf("ft_printf : ");
// // 	ret_ft = ft_printf("char : %c\n", 'a');
// // 	printf("ft_printf return value : %d\n", ret_ft);
// // 	/*test with wrong specifier*/
// // 	printf("printf with percentage z: ");
// // 	ret_original = printf("char : %z\n", 'c');
// // 	ft_printf("ft_printf with percentage z: ");
// // 	ret_ft = ft_printf("char : %z\n", 'c');
	
// // 	// /*test with flags*/
// // 	printf("%d\n", ft_printf("%c\n", '0'));
// // 	printf("printf spec c with flag - : ");
// // 	ret_original = printf("%-10c|\n", 'a');
// // 	printf("printf return value : %d\n", ret_original);
// // 	ft_printf("ft_printf spec c with flag - : ");
// // 	ret_ft = ft_printf("%-10c|\n", 'a');
// // 	printf("ft_printf return value : %d\n", ret_ft);
// // 	printf("printf with flag : ");
// // 	ret_original = printf("%.10c|\n", 'a');
// // 	printf("printf return value : %d\n", ret_original);
// // 	ft_printf("ft_printf with flag : ");
// // 	ret_ft = ft_printf("%.10c|\n", 'a');
// // 	printf("ft_printf return value : %d\n", ret_ft);

// // 	ret_original = printf("");
// // 	printf("printf empty string return value : %d\n", ret_original);
// // 	ret_ft = ft_printf("");
// // 	printf("ft_printf empty string return value : %d\n", ret_original);
// // 	ft_printf("ft_printf decimal: %d\n", 10);
// // 	printf("printf : %c\n", '%');
// // 	ft_printf("ft_printf : %c\n", '%');
	
// // // 	/* %d and %i*/
// // 	printf("%d\n", printf("decimal: %05d|\n", 10));
// // 	printf("%d\n", ft_printf("decimal: %05d|\n", 10));
// // 	printf("%d\n", printf("decimal: %5d|\n", -10));
// // 	printf("%d\n", ft_printf("decimal: %5d|\n", -10));
// // 	printf("integer: %.5i\n", 10);
// // 	ft_printf("integer: %.5i\n", 10);
// // 	printf("this %d number\n", 0);
// // 	ft_printf("this %d number\n", 0);
// // 	printf("%3d\n", 0);
// // 	ft_printf("%3d\n", 0);
// // 	printf("%-7d|\n", -14);
// // 	ft_printf("%-7d|\n", -14);
// // 	printf("%8.5d\n", 34);
// // 	ft_printf("%8.5d\n", 34);
// // 	printf("%10.5d|\n", -216);
// // 	ft_printf("%10.5d|\n", -216);
// // 	printf("%-10.5d|\n", -216);
// // 	ft_printf("%-10.5d|\n", -216);
// // 	printf("%-8.3d|\n", -8473);
// // 	ft_printf("%-8.3d|\n", -8473);
// // 	printf("%-08.5d|\n", 34);
// // 	ft_printf("%-08.5d|\n", 34);
// // // 	printf("%010.5d|\n", -216);
// // 	ft_printf("%010.5d|\n", -216);
	
// // 	printf("%08.5d|\n", 0);
// // 	ft_printf("%08.5d|\n", 0);
// // 	// // int d_prec_width_nf_pos_zp(void){return test("%08.3d", 8375);}
// // 	// // int d_prec_width_nf_neg_zp(void){return test("%08.3d", -8473);}
// // 	printf("%0-8.3d|\n", 8375);
// // 	ft_printf("%0-8.3d|\n", 8375);
// // 	// // int d_prec_width_nf_neg_ljzp_ignoreflag(void){return test("%0-8.3d", -8473);}
// // 	// // int d_prec_width_fn_pos_ljzp_ignoreflag(void){return test("%0-3.7d", 3267);}
// // 	// // int d_prec_width_fn_neg_ljzp_ignoreflag(void){return test("%0-3.7d", -2375);}
// // 	// // int d_prec_width_nn_pos_ljzp_ignoreflag(void){return test("%0-3.3d", 6983);}
// // 	// //int d_prec0val0_basic(void){return test
// // 	printf("%.0d|\n", 0);
// // 	ft_printf("%.0d|\n", 0);
// // 	// int d_prec0val0_implicit(void){return test("%.d", 0);}
// // 	// int d_prec0val0_w(void){return test("%5.0d", 0);}
// // 	// int d_prec0val0_w_impl(void){return test("%5.d", 0);}
// // 	// int d_prec0val0_wlj(void){return test("%-5.0d", 0);}
// // 	// int d_prec0val0_wlj_impl(void){return test
// // 	printf("%-5.d|\n", 0);
// // 	ft_printf("%-5.d|\n", 0);
// // 	printf(" %d \n", INT_MIN);
// // 	ft_printf(" %d \n", INT_MIN);

// // // 		/* %p */
// // static char	a01;
// // static unsigned char a02;
// // static short a03;
// // static unsigned short a04;
// // static int a05;
// // static unsigned int a06;
// // static long a07;
// // static unsigned long a08;
// // static long long a09;
// // static unsigned long long a10;
// // static char *a11;
// // static void *a12;
// // 	printf("printf : %d\n", printf("%p\n", p));
// // 	ft_printf("ft_printf : %d\n", printf("%p\n", p));
// // 	printf("printf : %d\n", printf(" %p \n", 1));
// // 	ft_printf("ft_printf : %d\n", printf(" %p \n", 1));
// // 	printf("FT_PF: %d\n", ft_printf(" %p \n", 1));
// // 	printf("PF: %d\n", printf(" %p \n", 1));
// // 	printf("FT_PF: %d\n", ft_printf(" %-2p ", 1));
// // 	printf("PF: %d\n", printf(" %-2p ", 1));
// // 	printf("FT_PF: %d\n", ft_printf(" %-10p %-9p |", INT_MIN, INT_MAX));
// // 	printf("PF: %d\n", printf(" %-10p %-9p |", INT_MIN, INT_MAX));
// // 	printf("PF: %d\n", printf(" %12p ", INT_MAX));
// // 	printf("FT_PF: %d\n", ft_printf(" %12p ", INT_MAX));
// // 	printf("PF: %d\n", printf(" %14p ", INT_MIN));
// // 	printf("FT_PF: %d\n", ft_printf(" %14p ", INT_MIN));
// // 	printf("FT_PF: %d\n", ft_printf(" %-16p |", 1));
// // 	printf("PF: %d\n", printf(" %-16p |", 1));

// // printf("FT_PF: %d\n", ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12));
// // printf("FT_PF: %d\n", ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12));
// // printf("PF: %d\n", printf("%13p|\n",&a01));
// // printf("FT_PF: %d\n", ft_printf("%13p|\n",&a01));

// // // 		/* %u */
// // 	printf("printf unsigned -10 becomes: %u\n", -10);
// // 	ft_printf("ft_printf unsigned -10 becomes: %u\n", -10);

// // // 		/* %x & %X */
// // 	printf("printf -10 in base 10 becomes : %.15x|\n", -10);
// // 	ft_printf("ft_printf -10 in base 10 becomes : %.15x|\n", -10);
// // 	printf("printf -10 in base 10 becomes : %X\n", -10);
// // 	ft_printf("ft_printf -10 in base 10 becomes : %X\n", -10);

// // // 		/* %% */
// // 	printf("printf : %%\n");
// // 	ft_printf("ft_printf : %%\n");
// // 	printf("printf : %%%%\n");
// // 	ft_printf("ft_printf : %%%%\n");
// // 	printf("printf : %%%%%%%\n");
// // 	ft_printf("ft_printf : %%%%%%%\n");
// // printf("FT_PF: %d\n", ft_printf("%5%|", 1));
// // printf("PF: %d\n", printf("%5%|", 1));
// // printf("FT_PF: %d\n", ft_printf("%05%|\n", 1));
// // printf("PF: %d\n", printf("%05%|\n", 1));
// // printf("FT_PF: %d\n", ft_printf("%-05c|\n", 1));
// // printf("PF: %d\n", printf("%-05c|\n", 1));
// // // 	// system("leaks a.out");
// }

// // #define FORMAT	"ddsvdsvds%l------\n"

// #define FORMAT	"%70p\n", 0 
// #define FORMAT	"%.5p\n", 0
// #define FORMAT	"%-10.5c\n", 'c'
// #define FORMAT "%#043X\n", 3
// #define FORMAT "|%#x|\n", 0
// #define FORMAT	"%+d\n", 5 
// #define FORMAT	"%.5p\n", 0
// // #define FORMAT	"%-10.5c\n", 'c' 
// #define FORMAT	"%#0.10p\n", 5
// #define FORMAT	"%5p\n", 0
// #define FORMAT " %-2p \n", 1
// #define FORMAT "%.u\n", 0
// #define FORMAT "%08.2x\n", 8
// #define FORMAT " %#x \n", 0
// #define FORMAT " %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42
// #define FORMAT "%#7x\n", 33
// #define FORMAT "|%#3x|\n", 0
// #define FORMAT "% .5d\n", 33
// #define FORMAT "% 3d\n", 0
// #define FORMAT "% -7d\n", 33
// #define FORMAT "% .5d\n", 2
// #define FORMAT "% .6d\n", -3
// #define FORMAT "% 8.5d\n", 34
// #define FORMAT "%#8.5x\n", 34
// #define FORMAT "%#8.5x\n", 0
// #define FORMAT "%+.7d\n", 234
// #define FORMAT "%+5d\n", 35
// #define FORMAT "%+05d\n", 432
// #define FORMAT "%#05x\n", 432
// #define FORMAT "%+.0d\n", 0
// #define FORMAT "%.4d\n", 5263
// #define FORMAT "%+-8.5d", 34
// #define FORMAT "%0+8.5d", 34
// #define FORMAT	"%70p\n", 0 
// #define FORMAT	"%.5p\n", 0
// #define FORMAT	"%-10.5c\n", 'c'
// #define FORMAT "%#043X\n", 3
// #define FORMAT "|%#x|\n", 0
// #define FORMAT	"%+d\n", 5 
// #define FORMAT	"%.5p\n", 0
// #define FORMAT	"%-10.5c\n", 'c' 
// #define FORMAT	"%#0.10p\n", 5
// #define FORMAT	"%5p\n", 0
// #define FORMAT " %-2p \n", 1
// #define FORMAT "%.u\n", 0
// #define FORMAT "%08.2x\n", 8
// #define FORMAT " %#x \n", 0
// #define FORMAT " %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42
// #define FORMAT "%#7x\n", 33
// #define FORMAT "|%#3x|\n", 0
// #define FORMAT "% .5d\n", 33
// #define FORMAT "% 3d\n", 0
// #define FORMAT "% -7d\n", 33
// #define FORMAT "% .5d\n", 2
// #define FORMAT "% .6d\n", -3
// #define FORMAT "% 8.5d\n", 34
// #define FORMAT "%#8.5x\n", 34
// #define FORMAT "%#8.5x\n", 0
// #define FORMAT "%#8.3x\n", 8375
// #define FORMAT "%+.7d\n", 234
// #define FORMAT "%+5d\n", 35
// #define FORMAT "%+05d\n", 432
// #define FORMAT "%#08.5x\n", 432
// #define FORMAT "%-+4.7d\n", 32
// #define FORMAT "%.4d\n", 5263
// #define FORMAT "%0+8.5d\n", 34
// #define FORMAT "%0+10.5d\n", -216
// #define FORMAT "%0+3.7d\n", 3267
// #define FORMAT "%0+-3.3d\n", -8462
// #define FORMAT "%0+-8.5d\n", 34
// #define FORMAT "% +-8.3d\n", 8375
// #define FORMAT "% 0+-8.3d\n", 8375
//  #define FORMAT "% 0+-3.3d\n", -8462
//  #define FORMAT "%#0-8.5x", 34
//  #define FORMAT "%#-5x\n", 52625
//  #define FORMAT "%%-d 42 == %-d\n", INT_MIN
// #define FORMAT "%%04i 42 == |%04i|\n", 42
//  #define FORMAT "%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e'
//  #define FORMAT "Kashim a %ld histoires à raconter\n", 1001
// #define FORMAT "%% 4.5i 42 == |% 4.5i|\n", 42
// #define FORMAT "%%#X INT_MIN ==  %#X\n", INT_MIN
// #define FORMAT ""
// #define FORMAT
// #define FORMAT
// #define FORMAT "%#7.3x\n", 8375
// #define FORMAT "%#8.3x\n", 8375
//  #define FORMAT "this %d number\n", 0
// #define FORMAT "%+-2.d\n", 0
// #define FORMAT "%.3d\n", 0
// #define FORMAT "%+-5.0i\n", 0
// #define FORMAT "%#7x", 33
// #define "%#-8.5x", 0
// #define "%#-2.7x", 3267
// #define "%#0-8.5x", 34
// #define "%#0-8.3x", 8375
// #define FORMAT "%-.3i\n", -10
// #define FORMAT "%-7.5d|\n", -5
// #define FORMAT "%-8.4d", -5
// #define FORMAT "%-10.d", -1
// #define FORMAT "%d\n", (int)-2147483648
// #define FORMAT "%5.p\n", NULL
// #define FORMAT "%p\n", NULL
// #define FORMAT "-->|%-16.p|<-- ", NULL
//#define FORMAT "%-10.u|\n", 5
// #define FORMAT "%20.5d", -1025
// #define FORMAT "%10c%0036.99%" ,9
// #define FORMAT "%03.c", 'c'
// #define FORMAT "%10c" ,9
static int ncm_p = 10;
#define FORMAT "%.p", &ncm_p
int	main(void)
{
	printf("Yours: %d\n", ft_printf(FORMAT));
	printf("Origi: %d\n", printf(FORMAT));
	return (0);
}