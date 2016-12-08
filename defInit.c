#include "defInit.h"

void defInit()
{
	size_t i = 0;
	dProc.MemorySize = 16*65536;
	dProc.MemoryCol = 65536;
	dProc.MemoryRow = 16;
	dProc.ASCII_min = 0x20;
	dProc.ASCII_max = 0x7E;
	dProc.hexByte_max = 0xFF;
	dProc.hash_max = 20;

	dProc.Memory = 
		(unsigned int**)malloc(sizeof(unsigned int**) * dProc.MemoryCol);

	for(i = 0; i != dProc.MemoryCol; ++i)
	{
		dProc.Memory[i] = (unsigned int*)calloc(sizeof(unsigned int*), dProc.MemoryRow);
	}
}
void defInit_free()
{
	size_t i=0;
	for(i=0; i != dProc.MemoryCol; ++i)
		free(dProc.Memory[i]);
	free(dProc.Memory);
}

char* allUpper(char *str)
{
	char *result;
	size_t i = 0;
	size_t len = strlen(str);
	result = (char*)malloc(sizeof(char)*len+1);
	for(i=0; i != len; ++i)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			result[i] = str[i] - 32;
		else
			result[i] = str[i];
	}
	result[i] = '\0';
	return result;
}

char* allLower(char *str)
{
	char *result;
	size_t i = 0;
	size_t len = strlen(str);
	result = (char*)malloc(sizeof(char)*len+1);
	for(i=0; i != len; ++i)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			result[i] = str[i] + 32;
		else
			result[i] = str[i];
	}
	result[i] = '\0';
	return result;
}
