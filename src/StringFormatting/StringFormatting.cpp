// StringFormatting.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdlib.h>  
#include <stdio.h>  
#include <stdarg.h>

int aswprintf(wchar_t **ret, const wchar_t *format, ...)
{
	va_list ap;

	*ret = NULL;  /* Ensure value can be passed to free() */

	va_start(ap, format);
	int count = _vsnwprintf(NULL, 0, format, ap);
	va_end(ap);

	if (count >= 0)
	{
		wchar_t* buffer = (wchar_t*)malloc((count + 1) * sizeof(wchar_t));
		if (buffer == NULL)
			return -1;

		va_start(ap, format);
		count = _vsnwprintf(buffer, count + 1, format, ap);
		va_end(ap);

		if (count < 0)
		{
			free(buffer);
			return count;
		}
		*ret = buffer;
	}

	return count;
}

int asprintf(char **ret, const char *format, ...)
{
	va_list ap;

	*ret = NULL;  /* Ensure value can be passed to free() */

	va_start(ap, format);
	int count = vsnprintf(NULL, 0, format, ap);
	va_end(ap);

	if (count >= 0)
	{
		char* buffer = (char*)malloc(count + 1);
		if (buffer == NULL)
			return -1;

		va_start(ap, format);
		count = vsnprintf(buffer, count + 1, format, ap);
		va_end(ap);

		if (count < 0)
		{
			free(buffer);
			return count;
		}
		*ret = buffer;
	}

	return count;
}

int main()
{
	char* str = NULL;
	asprintf(&str, "Hello ANSI %s %s %d\n", "foo", "bar", 123);
	printf(str);
	free(str);

	wchar_t* wstr = NULL;
	aswprintf(&wstr, L"Hello Unicode %s %s %d\n", L"foo", L"bar", 123);
	wprintf(wstr);
	free(wstr);
    return 0;
}

