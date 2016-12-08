#include "mnemonic.h"

// max hash size is 20
// dProc.hash_max = 20
hash_table *mnemonic_table = NULL;

int mnemonic(char *str)
{
	char *upper = NULL;
	char *result = NULL;
	upper = allUpper(str);
	result = find_hash(mnemonic_table, upper);
	// require free

	if(check_empty(result))
	{
		printf("mnemonic is NOT exist\n");
		free(upper);
		free(result);
		return 1;
	}
	else
	{
		printf("mnemonic is %s\n", result);
		free(upper);
		free(result);
	}
	return 0;
}

int mnemoniclist()
{
	slot *print = NULL;
	unsigned int i = 0;
	for(i=0; i != dProc.hash_max; ++i)
	{
		printf("%d : ", i);
		print = mnemonic_table[i].slot;
		if(print == NULL)
		{
			printf("\n");
			continue;
		}
		printf("[%s, %s] ", print->value, print->key);
		print = print->next;
		while(print != NULL)
		{
			printf("-> [%s, %s] ", print->value, print->key);
			print = print->next;
		}
		printf("\n");
	}
	return 0;
}

int make_mnemonic()
{
	char value[20];
	char op[20];
	char type[4];
	size_t check = 0;
	
	FILE *fp = fopen("opcode.txt", "r");
	if(fp == NULL)
		return 1;

	mnemonic_table = Init_hash_table(dProc.hash_max);
	while(check != EOF)
	{
		check = fscanf(fp, "%s	%s	%s\n", value, op, type);
		input_hash(mnemonic_table, value, op, type);
	}
	fclose(fp);

	return 0;
}

void free_mnemonic()
{
	size_t i = 0;
	if(mnemonic_table != NULL)
	{
		for(i=0; i != dProc.hash_max; ++i)
		{
			free_hash(mnemonic_table[i]);
		}
		free(mnemonic_table);
	}
}
