/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:27:48 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/06 22:17:19 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

void test_ft_atoi(void) {
    printf("Testing ft_atoi:\n");
    printf("Input: '42', Expected: %d, Got: %d\n", atoi("42"), ft_atoi("42"));
    printf("Input: '-42', Expected: %d, Got: %d\n", atoi("-42"), ft_atoi("-42"));
    printf("Input: '   +1234', Expected: %d, Got: %d\n", atoi("   +1234"), ft_atoi("   +1234"));
    printf("Input: 'a42', Expected: %d, Got: %d\n\n", atoi("a42"), ft_atoi("a42"));
}

void test_ft_bzero(void) {
    printf("Testing ft_bzero:\n");
    char b1[10] = "abcdefghi";
    char b2[10] = "abcdefghi";
    bzero(b1, 5);
    ft_bzero(b2, 5);
    printf("Expected: %s, Got: %s\n\n", b1, b2);
}

void test_ft_isalnum(void) {
    printf("Testing ft_isalnum:\n");
    printf("Input: 'A', Expected: %d, Got: %d\n", isalnum('A'), ft_isalnum('A'));
    printf("Input: '1', Expected: %d, Got: %d\n", isalnum('1'), ft_isalnum('1'));
    printf("Input: '*', Expected: %d, Got: %d\n\n", isalnum('*'), ft_isalnum('*'));
}

void test_ft_isalpha(void) {
    printf("Testing ft_isalpha:\n");
    printf("Input: 'A', Expected: %d, Got: %d\n", isalpha('A'), ft_isalpha('A'));
    printf("Input: 'z', Expected: %d, Got: %d\n", isalpha('z'), ft_isalpha('z'));
    printf("Input: '1', Expected: %d, Got: %d\n\n", isalpha('1'), ft_isalpha('1'));
}

void test_ft_isascii(void) {
    printf("Testing ft_isascii:\n");
    printf("Input: 65, Expected: %d, Got: %d\n", isascii(65), ft_isascii(65));
    printf("Input: 128, Expected: %d, Got: %d\n\n", isascii(128), ft_isascii(128));
}

void test_ft_isdigit(void) {
    printf("Testing ft_isdigit:\n");
    printf("Input: '0', Expected: %d, Got: %d\n", isdigit('0'), ft_isdigit('0'));
    printf("Input: '9', Expected: %d, Got: %d\n", isdigit('9'), ft_isdigit('9'));
    printf("Input: 'a', Expected: %d, Got: %d\n\n", isdigit('a'), ft_isdigit('a'));
}

void test_ft_isprint(void) {
    printf("Testing ft_isprint:\n");
    printf("Input: ' ', Expected: %d, Got: %d\n", isprint(' '), ft_isprint(' '));
    printf("Input: 127, Expected: %d, Got: %d\n\n", isprint(127), ft_isprint(127));
}

void test_ft_memchr(void) {
    printf("Testing ft_memchr:\n");
    char s[] = "Hello, world!";
    printf("Input: 'o', Expected: %s, Got: %s\n\n", (char *)memchr(s, 'o', 13), (char *)ft_memchr(s, 'o', 13));
}

void test_ft_memcmp(void) {
    printf("Testing ft_memcmp:\n");
    char s1[] = "Hello, world!";
    char s2[] = "Hello, World!";
    printf("Input: 'Hello, world!' vs 'Hello, World!', Expected: %d, Got: %d\n\n", memcmp(s1, s2, 13), ft_memcmp(s1, s2, 13));
}

void test_ft_memcpy(void) {
    printf("Testing ft_memcpy:\n");
    char dest1[20] = {0};
    char dest2[20] = {0}; 
    memcpy(dest1, "Hello, world!", 13);
    dest1[13] = '\0';
    ft_memcpy(dest2, "Hello, world!", 13);
    dest2[13] = '\0';
    printf("Expected: %s, Got: %s\n\n", dest1, dest2);
}

void test_ft_memmove(void) {
    printf("Testing ft_memmove:\n");
    char dest1[20] = "Hello, world!";
    char dest2[20] = "Hello, world!";
    memmove(dest1 + 6, dest1, 5);
    ft_memmove(dest2 + 6, dest2, 5);
    printf("Expected: %s, Got: %s\n\n", dest1, dest2);
}

void test_ft_memset(void) {
    printf("Testing ft_memset:\n");
    char s1[20] = "Hello, world!";
    char s2[20] = "Hello, world!";
    memset(s1, '*', 5);
    ft_memset(s2, '*', 5);
    printf("Expected: %s, Got: %s\n\n", s1, s2);
}

void test_ft_strchr(void) {
    printf("Testing ft_strchr:\n");
    char s[] = "Hello, world!";
    printf("Input: 'o', Expected: %s, Got: %s\n\n", strchr(s, 'o'), ft_strchr(s, 'o'));
}

void test_ft_strlcat(void) {
    printf("Testing ft_strlcat:\n");
    char dest1[20] = "Hello, ";
    char dest2[20] = "Hello, ";
    printf("Expected: %zu, Got: %zu\n", strlcat(dest1, "world!", 20), ft_strlcat(dest2, "world!", 20));
    printf("Result: Expected: %s, Got: %s\n\n", dest1, dest2);
}

void test_ft_strlcpy(void) {
    printf("Testing ft_strlcpy:\n");
    char dest1[20];
    char dest2[20];
    printf("Expected: %zu, Got: %zu\n", strlcpy(dest1, "Hello, world!", 20), ft_strlcpy(dest2, "Hello, world!", 20));
    printf("Result: Expected: %s, Got: %s\n\n", dest1, dest2);
}

void test_ft_strlen(void) {
    printf("Testing ft_strlen:\n");
    printf("Input: 'Hello, world!', Expected: %zu, Got: %d\n\n", strlen("Hello, world!"), ft_strlen("Hello, world!"));
}

void test_ft_strncmp(void) {
    printf("Testing ft_strncmp:\n");
    printf("Input: 'Hello' vs 'Hello', 5, Expected: 0, Got: %d\n", ft_strncmp("Hello", "Hello", 5));
    printf("Input: 'Hello' vs 'World', 5, Expected: -1, Got: %d\n", ft_strncmp("Hello", "World", 5));
    printf("Input: 'Hello' vs 'HelLo', 5, Expected: 0, Got: %d\n", ft_strncmp("Hello", "HelLo", 5));
    printf("Input: 'Hello' vs 'Hell', 5, Expected: 'o', Got: %d\n\n", ft_strncmp("Hello", "Hell", 5));
}

void test_ft_strnstr(void) {
    printf("Testing ft_strnstr:\n");
    char big[] = "Hello, world!";
    char little[] = "world";
    printf("Expected: %s, Got: %s\n\n", strnstr(big, little, 13), ft_strnstr(big, little, 13));
}

void test_ft_strrchr(void) {
    printf("Testing ft_strrchr:\n");
    char s[] = "Hello, world!";
    printf("Input: 'o', Expected: %s, Got: %s\n\n", strrchr(s, 'o'), ft_strrchr(s, 'o'));
}

void test_ft_tolower(void) {
    printf("Testing ft_tolower:\n");
    printf("Input: 'A', Expected: %d, Got: %d\n", tolower('A'), ft_tolower('A'));
    printf("Input: 'a', Expected: %d, Got: %d\n\n", tolower('a'), ft_tolower('a'));
}

void test_ft_toupper(void) {
    printf("Testing ft_toupper:\n");
    printf("Input: 'a', Expected: %d, Got: %d\n", toupper('a'), ft_toupper('a'));
    printf("Input: 'A', Expected: %d, Got: %d\n\n", toupper('A'), ft_toupper('A'));
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
	return 0;
}
