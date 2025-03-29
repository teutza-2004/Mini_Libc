// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *c;
	for (c = destination; *source != '\0'; c++, source++)
		*c = *source;
	*c = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *c;
	size_t nr = 0;
	for (c = destination; *source != '\0' && nr < len; c++, source++, nr++)
		*c = *source;
	*c = *source;
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *c;
	for (c = destination; *c != '\0'; c++)
		;
	for (; *source != '\0'; source++, c++)
		*c = *source;
	*c = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *c;
	size_t nr = 0;
	for (c = destination; *c != '\0'; c++)
		;
	for (; *source != '\0' && nr < len; source++, c++, nr++)
		*c = *source;
	*c = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++)
		if(*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
	if (*str1 != '\0')
		return 1;
	if (*str2 != '\0')
		return -1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t nr = 0;
	for (; *str1 != '\0' && *str2 != '\0' && nr < len; str1++, str2++, nr++)
		if(*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
	if (nr == len)
		return 0;
	if (*str1 != '\0')
		return 1;
	if (*str2 != '\0')
		return -1;
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for (; *str != '\0'; str++)
		if (*str == c)
			return (char *)str;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *ret = NULL;
	for (; *str != '\0'; str++)
		if (*str == c)
			ret = (char *)str;
	return ret;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	for (; *haystack != '\0'; haystack++)
		if (*haystack == *needle) {
			char *h = (char *)haystack, *n = (char *)needle;
			for (; *h != '\0' && *n != '\0'; h++, n++)
				if (*h != *n)
					break;
			if (*n == '\0')
				return (char *)haystack;
		}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *ret = NULL;
	for (; *haystack != '\0'; haystack++)
		if (*haystack == *needle) {
			char *h = (char *)haystack, *n = (char *)needle;
			for (; *h != '\0' && *n != '\0'; h++, n++)
				if (*h != *n)
					break;
			if (*n == '\0')
				ret = (char *)haystack;
		}
	return ret;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = (char *)destination;
	char *dest = d;
	char *s = (char *)source;
	for (size_t i = 0; i < num; i++, d++, s++)
		*d = *s;
	destination = dest;
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *d = (char *)destination;
	char *dest = d;
	char *s = (char *)source;
	for (size_t i = 0; i < num; i++, d++, s++)
		*d = *s;
	destination = dest;
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *str1 = (char *)ptr1;
	char *str2 = (char *)ptr2;
	size_t nr = 0;
	for (; *str1 != '\0' && *str2 != '\0' && nr < num; str1++, str2++, nr++)
		if(*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
	if (nr == num)
		return 0;
	if (*str1 != '\0')
		return 1;
	if (*str2 != '\0')
		return -1;
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *s = (char *)source;
	char *ret = s;
	for (size_t i = 0; i < num; i++, s++)
		*s = (char)value;
	source = ret;
	return source;
}
