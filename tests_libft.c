/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:27:48 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/08 20:13:17 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

// Macros pour les couleurs
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

void print_test_result(int success) {
    if (success) {
        printf(GREEN "OK" RESET "\n");
    } else {
        printf(RED "KO" RESET "\n");
    }
}

void test_ft_atoi(void) {
    printf("Testing ft_atoi:\n");
    print_test_result(atoi("42") == ft_atoi("42"));
    print_test_result(atoi("-42") == ft_atoi("-42"));
    print_test_result(atoi("   +1234") == ft_atoi("   +1234"));
    print_test_result(atoi("a42") == ft_atoi("a42"));
}

void test_ft_bzero(void) {
    printf("Testing ft_bzero:\n");
    char b1[10] = "abcdefghi";
    char b2[10] = "abcdefghi";
    bzero(b1, 5);
    ft_bzero(b2, 5);
    print_test_result(memcmp(b1, b2, 10) == 0);
}

void test_ft_isalnum(void) {
    printf("Testing ft_isalnum:\n");
    print_test_result(isalnum('A') == ft_isalnum('A'));
    print_test_result(isalnum('1') == ft_isalnum('1'));
    print_test_result(isalnum('*') == ft_isalnum('*'));
}

void test_ft_isalpha(void) {
    printf("Testing ft_isalpha:\n");
    print_test_result(isalpha('A') == ft_isalpha('A'));
    print_test_result(isalpha('z') == ft_isalpha('z'));
    print_test_result(isalpha('1') == ft_isalpha('1'));
}

void test_ft_isascii(void) {
    printf("Testing ft_isascii:\n");
    print_test_result(isascii(65) == ft_isascii(65));
    print_test_result(isascii(128) == ft_isascii(128));
}

void test_ft_isdigit(void) {
    printf("Testing ft_isdigit:\n");
    print_test_result(isdigit('0') == ft_isdigit('0'));
    print_test_result(isdigit('9') == ft_isdigit('9'));
    print_test_result(isdigit('a') == ft_isdigit('a'));
}

void test_ft_isprint(void) {
    printf("Testing ft_isprint:\n");
    print_test_result(isprint(' ') == ft_isprint(' '));
    print_test_result(isprint(127) == ft_isprint(127));
}

void test_ft_memchr(void) {
    printf("Testing ft_memchr:\n");
    char s[] = "Hello, world!";
    print_test_result(memchr(s, 'o', 13) == ft_memchr(s, 'o', 13));
}

void test_ft_memcmp(void) {
    printf("Testing ft_memcmp:\n");
    char s1[] = "Hello, world!";
    char s2[] = "Hello, World!";
    print_test_result(memcmp(s1, s2, 13) == ft_memcmp(s1, s2, 13));
}

void test_ft_memcpy(void) {
    printf("Testing ft_memcpy:\n");
    char dest1[20] = {0};
    char dest2[20] = {0};
    memcpy(dest1, "Hello, world!", 13);
    ft_memcpy(dest2, "Hello, world!", 13);
    print_test_result(memcmp(dest1, dest2, 13) == 0);
}

void test_ft_memmove(void) {
    printf("Testing ft_memmove:\n");
    char dest1[20] = "Hello, world!";
    char dest2[20] = "Hello, world!";
    memmove(dest1 + 6, dest1, 5);
    ft_memmove(dest2 + 6, dest2, 5);
    print_test_result(memcmp(dest1, dest2, 13) == 0);
}

void test_ft_memset(void) {
    printf("Testing ft_memset:\n");
    char s1[20] = "Hello, world!";
    char s2[20] = "Hello, world!";
    memset(s1, '*', 5);
    ft_memset(s2, '*', 5);
    print_test_result(memcmp(s1, s2, 13) == 0);
}

void test_ft_strchr(void) {
    printf("Testing ft_strchr:\n");
    char s[] = "Hello, world!";
    print_test_result(strchr(s, 'o') == ft_strchr(s, 'o'));
}

void test_ft_strlcat(void) {
    printf("Testing ft_strlcat:\n");
    char dest1[20] = "Hello, ";
    char dest2[20] = "Hello, ";
    size_t result1 = strlcat(dest1, "world!", 20);
    size_t result2 = ft_strlcat(dest2, "world!", 20);
    print_test_result(result1 == result2 && strcmp(dest1, dest2) == 0);
}

void test_ft_strlcpy(void) {
    printf("Testing ft_strlcpy:\n");
    char dest1[20];
    char dest2[20];
    size_t result1 = strlcpy(dest1, "Hello, world!", 20);
    size_t result2 = ft_strlcpy(dest2, "Hello, world!", 20);
    print_test_result(result1 == result2 && strcmp(dest1, dest2) == 0);
}

void test_ft_strlen(void) {
    printf("Testing ft_strlen:\n");
    print_test_result(strlen("Hello, world!") == ft_strlen("Hello, world!"));
}

void test_ft_strncmp(void) {
    printf("Testing ft_strncmp:\n");
    print_test_result(strncmp("Hello", "Hello", 5) == ft_strncmp("Hello", "Hello", 5));
    print_test_result(0 > ft_strncmp("Hello", "World", 5));
    print_test_result(0 < ft_strncmp("Hello", "HelLo", 5));
    print_test_result(0 < ft_strncmp("Hello", "Hell", 5));
}

void test_ft_strnstr(void) {
    printf("Testing ft_strnstr:\n");
    char big[] = "Hello, world!";
    char little[] = "world";
    print_test_result(strnstr(big, little, 13) == ft_strnstr(big, little, 13));
}

void test_ft_strrchr(void) {
    printf("Testing ft_strrchr:\n");
    char s[] = "Hello, world!";
    print_test_result(strrchr(s, 'o') == ft_strrchr(s, 'o'));
}

void test_ft_tolower(void) {
    printf("Testing ft_tolower:\n");
    print_test_result(tolower('A') == ft_tolower('A'));
    print_test_result(tolower('a') == ft_tolower('a'));
}

void test_ft_toupper(void) {
    printf("Testing ft_toupper:\n");
    print_test_result(toupper('a') == ft_toupper('a'));
    print_test_result(toupper('A') == ft_toupper('A'));
}

void test_ft_strtrim(void) {
    printf("Testing ft_strtrim:\n");
    char *s1 = "   Hello, world!   ";
    char *set = " ";
    char *expected = "Hello, world!";
    char *result = ft_strtrim(s1, set);
    print_test_result(strcmp(expected, result) == 0);
    free(result);
}

void test_ft_strdup(void) {
    printf("Testing ft_strdup:\n");
    char *s = "Hello, world!";
    char *expected = strdup(s);
    char *result = ft_strdup(s);
    print_test_result(strcmp(expected, result) == 0);
    free(expected);
    free(result);
}

void test_ft_strjoin(void) {
    printf("Testing ft_strjoin:\n");
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *expected = "Hello, world!";
    char *result = ft_strjoin(s1, s2);
    print_test_result(strcmp(expected, result) == 0);
    free(result);
}

void test_ft_substr(void) {
    printf("Testing ft_substr:\n");
    char *s = "Hello, world!";
    unsigned int start = 7;
    size_t len = 5;
    char *expected = "world";
    char *result = ft_substr(s, start, len);
    print_test_result(strcmp(expected, result) == 0);
    free(result);
}

void test_ft_split(void) {
    printf("Testing ft_split:\n");

    char **result = ft_split("Hello, world!", ' ');
    char *expected[] = {"Hello,", "world!", NULL};
    int i = 0;
    int success = 1;

    while (expected[i] && result[i]) {
        if (strcmp(expected[i], result[i]) != 0) {
            success = 0;
            break;
        }
        i++;
    }

    if (expected[i] != NULL || result[i] != NULL) {
        success = 0;
    }

    print_test_result(success);

    // Free allocated memory
    i = 0;
    while (result[i]) {
        free(result[i]);
        i++;
    }
    free(result);
}

void test_ft_itoa(void) {
    printf("Testing ft_itoa:\n");

    print_test_result(strcmp(ft_itoa(0), "0") == 0);
    print_test_result(strcmp(ft_itoa(42), "42") == 0);
    print_test_result(strcmp(ft_itoa(-42), "-42") == 0);
    print_test_result(strcmp(ft_itoa(123456), "123456") == 0);
    print_test_result(strcmp(ft_itoa(-123456), "-123456") == 0);
    print_test_result(strcmp(ft_itoa(-2147483648), "-2147483648") == 0);
}




int main(void) {
    test_ft_atoi();
    test_ft_bzero();
    test_ft_isalnum();
    test_ft_isalpha();
    test_ft_isascii();
    test_ft_isdigit();
    test_ft_isprint();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_memset();
    test_ft_strchr();
    test_ft_strlcat();
    test_ft_strlcpy();
    test_ft_strlen();
    test_ft_strncmp();
    test_ft_strnstr();
    test_ft_strrchr();
    test_ft_tolower();
    test_ft_toupper();
    test_ft_strtrim();
    test_ft_strdup();
    test_ft_strjoin();
    test_ft_substr();
	test_ft_split();
	test_ft_itoa();
    return 0;
}
