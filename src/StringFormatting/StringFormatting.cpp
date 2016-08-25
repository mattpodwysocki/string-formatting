// StringFormatting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "asprintf.h"

int main()
{
	char* str = NULL;
    if (_asprintf(&str, "Hello ANSI %s %s %d\n", "foo", "bar", 123) < 0)
        return -1;
	printf(str);
	free(str);

	wchar_t* wstr = NULL;
    if (_aswprintf(&wstr, L"Hello Unicode %s %s %d\n", L"foo", L"bar", 123) < 0)
        return -1;
	wprintf(wstr);
	free(wstr);

    system("pause");

    return 0;
}

