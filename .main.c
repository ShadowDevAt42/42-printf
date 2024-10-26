#include <stdio.h>
#include <limits.h> // Pour LONG_MIN, LONG_MAX, ULONG_MAX
#include "ft_printf.h"

int	main(void)
{
	char			*empty_str;
	char			*null_str;
	unsigned int	u_num;
	unsigned int	small_num;
	int				a;
	int				*ptr;
	unsigned int	hex_num;

	// 1. Test pour %s (chaînes de caractères)
	printf("\n=== Test 1: Strings (%%s) ===\n");
	printf("Standard printf: Hello %s!\n", "Shadow");
	ft_printf("Custom  ft_printf: Hello %s!\n", "Shadow");

	empty_str = "";
	null_str = NULL;

	printf("Standard printf: Empty string: %s\n", empty_str);
	ft_printf("Custom  ft_printf: Empty string: %s\n", empty_str);

	printf("Standard printf: Null string: %s\n", null_str);
	ft_printf("Custom  ft_printf: Null string: %s\n", null_str);

	// 2. Test pour %d et %i (entiers signés)
	printf("\n=== Test 2: Signed integers (%%d, %%i) ===\n");
	printf("Standard printf: Positive number (%%d): %d\n", 123);
	ft_printf("Custom  ft_printf: Positive number (%%d): %d\n", 123);

	printf("Standard printf: Negative number (%%d): %d\n", -123);
	ft_printf("Custom  ft_printf: Negative number (%%d): %d\n", -123);

	printf("Standard printf: Zero (%%d): %d\n", 0);
	ft_printf("Custom  ft_printf: Zero (%%d): %d\n", 0);

	printf("Standard printf: Integer (%%i): %i\n", 456);
	ft_printf("Custom  ft_printf: Integer (%%i): %i\n", 456);

	printf("Standard printf: Negative integer (%%i): %i\n", -456);
	ft_printf("Custom  ft_printf: Negative integer (%%i): %i\n", -456);

	// 3. Test pour %u (entiers non signés)
	printf("\n=== Test 3: Unsigned integers (%%u) ===\n");
	u_num = 4294967295;
	small_num = 42;

	printf("Standard printf: Unsigned int (max): %u\n", u_num);
	ft_printf("Custom  ft_printf: Unsigned int (max): %u\n", u_num);

	printf("Standard printf: Unsigned int (small): %u\n", small_num);
	ft_printf("Custom  ft_printf: Unsigned int (small): %u\n", small_num);

	// 4. Test pour %c (caractères)
	printf("\n=== Test 4: Characters (%%c) ===\n");
	printf("Standard printf: Character (%%c): %c\n", 'A');
	ft_printf("Custom  ft_printf: Character (%%c): %c\n", 'A');

	printf("Standard printf: Null character (%%c): %c\n", '\0');
	ft_printf("Custom  ft_printf: Null character (%%c): %c\n", '\0');

	// 5. Test pour %p (pointeurs)
	printf("\n=== Test 5: Pointers (%%p) ===\n");
	a = 42;
	ptr = &a;

	printf("Standard printf: Pointer to 'a': %p\n", (void *)ptr);
	ft_printf("Custom  ft_printf: Pointer to 'a': %p\n", (void *)ptr);

	printf("Standard printf: NULL pointer: %p\n", NULL);
	ft_printf("Custom  ft_printf: NULL pointer: %p\n", NULL);

	// 6. Test pour %% (affichage du signe de pourcentage)
	printf("\n=== Test 6: Percent sign (%%) ===\n");
	printf("Standard printf: 100%% complete!\n");
	ft_printf("Custom  ft_printf: 100%% complete!\n");

	printf("Standard printf: Just a percent sign: %%\n");
	ft_printf("Custom  ft_printf: Just a percent sign: %%\n");

	// 7. Test pour %x (hexadécimal en minuscules)
	hex_num = 305441741;
	printf("\n=== Test 7: Hexadecimal (%%x) ===\n");
	printf("Standard printf: Hexadecimal (%%x): %x\n", hex_num);
	ft_printf("Custom  ft_printf: Hexadecimal (%%x): %x\n", hex_num);

	// 8. Test pour %X (hexadécimal en majuscules)
	printf("\n=== Test 8: Hexadecimal (%%X) ===\n");
	printf("Standard printf: Hexadecimal (%%X): %X\n", hex_num);
	ft_printf("Custom  ft_printf: Hexadecimal (%%X): %X\n", hex_num);

	// 9. Test pour %p avec LONG_MIN et LONG_MAX
	printf("\n=== Test 9: Pointers with LONG_MIN and LONG_MAX ===\n");
	printf("Standard printf: %p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf("Custom  ft_printf: %p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);

	// 10. Test pour %p avec ULONG_MAX et -ULONG_MAX
	printf("\n=== Test 10: Pointers with ULONG_MAX and -ULONG_MAX ===\n");
	printf("Standard printf: %p %p\n", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
	ft_printf("Custom  ft_printf: %p %p\n", (void *)ULONG_MAX, (void *)(-ULONG_MAX));

	return (0);
}
