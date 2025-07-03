#include <stdio.h>
#include <string.h>
#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
#include "ex12/ft_print_memory.c"

void print_arr(char *arr)
{
	int i = 0;
    while (arr[i])
    {
        printf("%c", arr[i]);
        i++;
    }
}

int	main(void)
{
	printf("---testing ex00, expected output, catnip, (official f) catnip---\n");
	char dest[] = "         ";
	char src[] = "catnip";
	char *testdest;
	testdest = ft_strcpy(dest, src);
	printf("dest=%s\n", dest);
	printf("testdest=%s\n", testdest);

	strcpy(dest, src);
	printf("official=%s", dest);

	printf("\n---testing ex01, expected output, cat catnipin, official cat canipin---\n");
	char dest1[] = "   in";
	char dest11[] = "   in";
	char src1[] = "catnip";
	ft_strncpy(dest1, src1, 3);
	printf("dest1=%s\n", dest1);
	ft_strncpy(dest11, src1, 3);
	printf("official=%s\n", dest11);
	
	char dest21[] = "      in";
	char dest22[] = "      in";
	strncpy(dest21, src1, sizeof(dest21));
	printf("dest21=%s\n", dest21);
	strncpy(dest22, src1, sizeof(dest22));
	printf("official=%s", dest22);

	printf("\n---testing ex02, expected output, 1, 0 (1 true, 0 false)---\n");
	char ex1[] = "qwertyuiopasdfghjklzxcvbnmADWDWUNIFNAIOFNWICWNUVBWAUV";
	char ex2[] = "wadADWDz12Z44rwfaf43eaefr32rawf332WFAUFWAUFHI";
	int i1 = ft_str_is_alpha(ex1);
	int i2 = ft_str_is_alpha(ex2);
	printf("%d, %d", i1, i2);

	printf("\n---testing ex03, expected output 1, 0 (1 true, 0 false)---\n");
	char ex3[] = "1234567890";
	char ex4[] = "12324dawdZwd213dwaad123";
	i1 = ft_str_is_numeric(ex3);
	i2 = ft_str_is_numeric(ex4);
	printf("%d, %d", i1, i2);

	printf("\n---testing ex04, expected 1, 0 (1 true, 0 false)---\n");
	char ex5[] = "qwertyuiopasdfghjklzxcvbnm";
	char ex6[] = "wadAWDA1Z244rwfaf43eaefr32rawf332WFAUFWAUFHI";
	i1 = ft_str_is_lowercase(ex5);
	i2 = ft_str_is_lowercase(ex6);
	printf("%d, %d", i1, i2);
	
	printf("\n---testing ex05, expected 1, 0 (1 true, 0 false)---\n");
	char ex7[] = "AQWERTYUIOOPPPAASDFGHJKLZXCVBNMMZ";
	char ex8[] = "AWDAfesfs1Z244rwfaf43eaefr32rawf332WFAUFWAUFHI";
	i1 = ft_str_is_uppercase(ex7);
	i2 = ft_str_is_uppercase(ex8);
	printf("%d, %d", i1, i2);

	printf("\n---testing ex06, expected 1, 0 (1 true, 0 false)---\n");
	char ex9[] = "dwdadadafwdwadw21355555!!!@$$%^^&&*fafwaf22145y5hvvsvd.wd";
	char ex10[] = {'d', '1', '!', 31, 12, 34, 12, 1};
	i1 = ft_str_is_printable(ex9);
	i2 = ft_str_is_printable(ex10);
	printf("%d, %d", i1, i2);

	printf("\n---testing ex07, expected, ABCDXYZABCDXYZ---\n");
	char ex11[] = "abcdxyzABCDxyz";
	ft_strupcase(ex11);
	print_arr(ex11);

	printf("\n---testing ex08, expected, abcdxyzabcdxyz---\n");
	char ex12[] = "ABCDXYZabcdXYZ";
	ft_strlowcase(ex12);
	print_arr(ex12);

	printf("\n---testing ex09, expected, Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un---\n");
	char ex13[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(ex13);
	print_arr(ex13);
	printf("...");

	printf("\n---testing ex10, expected, 9 size of dest (cat + \\0),6 len returned, catnip--\n");
	char dest3[] = "      in";
	char src3[] = "catnip";
	unsigned int i = ft_strlcpy(dest3, src3, sizeof(src3));
	ft_strlcpy(dest3, src3, sizeof(src3));
	printf("%lu, %d, %s", sizeof(dest3), i, dest3);

	printf("\n---testing ex11, expected \\01 to \\1F,  !\"#...i\n---");
	char inv[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,25 ,26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
	ft_putstr_non_printable(inv);

	printf("\n---testing ex12---\n");
	char c_mem[] = "1234567d\n\n\n\n\n\n\n\n\n\n1294295712502*(@*@#*!@@#890123456abcdefghijklmnouprstwxyzdkawiofjwiaunaunoiuguoigabghbagiuaefsefes32";
	ft_print_memory(c_mem, sizeof(c_mem));
}
