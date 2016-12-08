#include "myHash.h"

size_t break_string(char *str);

hash_table* Init_hash_table(size_t max)
{
	size_t i = 0;
	hash_table *table = (hash_table*)malloc(sizeof(hash_table) * max);
	for(i=0; i != max; ++i)
	{
		table[i].count = 0;
		table[i].slot = NULL;
	}
	return table;
}

int input_hash(hash_table *table, char *str, char *value, char *type)
{
	size_t index = 0;
	slot *input = NULL;
	slot *temp;
	index = hash_key(str);
	input = (slot*)malloc(sizeof(slot));
	strcpy(input->key, str);
	strcpy(input->value, value);
	strcpy(input->type, type);
	input->next = NULL;
	
//	printf("input hash start, key = %d\n", index);

	if(table[index].slot == NULL)
		table[index].slot = input;
	else
	{
		temp = table[index].slot;
		while(temp->next != NULL)
			temp = temp->next;

		temp->next = input;
	}
	table[index].count++;
//	printf("%s\n", table[index].slot->key);

//	printf("input hash end\n");
	return 0;
}
char* find_hash(hash_table *table, char *key)
{
	char *result;
	size_t index = hash_key(key);
	slot* temp = table[index].slot;
	while(temp != NULL)
	{
		if(strcmp(temp->key, key)==0)
			break;
		temp = temp->next;
	}
	result = (char*)malloc(sizeof(char) * 20);
	if(temp == NULL)
		strcpy(result, "empty");
	else
		strcpy(result, temp->value);

	return result;
}

size_t hash_key(char *str)
{
	size_t key = 0;
	key = break_string(str);
	return (key % 20);
}

void free_hash(hash_table free_hash)
{
	slot *del = free_hash.slot;
	slot *temp = del;
	while(temp != NULL)
	{
		del = temp;
		temp = temp->next;
		free(del);
	}
}

size_t break_string(char *str)
{
	size_t result = 0;
	int len = strlen(str);
	size_t i=0;
	for(i=0; i != len; ++i)
		result += str[i]+'s';

	return result;
}
