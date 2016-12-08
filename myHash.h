#ifndef __myHash__
#define __myHash__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct _list
{
	char key[20];
	char value[20];
	char type[4];
	struct _list *next;
};

struct _hash
{
	unsigned int count;
	struct _list *slot;
};

typedef struct _list slot;
typedef struct _hash hash_table;

hash_table* Init_hash_table(size_t max);
int input_hash(hash_table *table, char *str, char *value, char *type);
char* find_hash(hash_table *table, char *key);
// require free retuner

size_t hash_key(char *str);
void free_hash(hash_table free_hash);

#endif
