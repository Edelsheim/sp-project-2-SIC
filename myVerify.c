#include "myVerify.h"
int changeASCII(char a)
{
	int result = 0;
	if(a >= 'A' && a <= 'F')
		result = a - 55;
	else if(a >= 'a' && a <= 'f')
		result = a - 87;
	else if(a >= '0' && a <= '9')
		result = a - 48;
	return result;
}

int check_empty(char *str)
{
	if(strcmp(str, "empty")==0)
		return 1;

	return 0;
}

int string_to_hex(char *str)
{
	int result = 0;
	int len = strlen(str);
	if(len >= 2)
	{
		result = changeASCII(str[len-1]);
		result += changeASCII(str[len-2])*0x10;
	}
	else if(len == 1)
	{
		result = changeASCII(str[0]);
	}
	else
		result = -1;

	return result;
}
