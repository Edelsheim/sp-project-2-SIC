#include "myStrtok.h"

int queue_empty();
void token_insert(char *str);

struct _token
{
	char *token;
	struct _token *next;
};

typedef struct _token token_queue;

token_queue *queue_head = NULL;

int myStrtok(char *str)
{
	myStrtok_count = -1;
	char temp[255];
	char *token;
	char *common;
	strcpy(temp, str);

	if(!queue_empty())
		free_myStrtok();

	token = strtok_r(temp, ", \r\t\n", &common);
	if(token == NULL)
		return 1;

	token_insert(token);
	++myStrtok_count;
	// count is 0
	// default count is -1

	while(1)
	{
		token = strtok_r(NULL, ", \r\t\n", &common);

		if(token == NULL)
			break;

		token_insert(token);
		++myStrtok_count;
	}
	return 0;
}

char* myStrtok_pop()
{
	char *buff;
	token_queue *current = queue_head;
	if(queue_empty())
	{
		buff = (char*)malloc(sizeof(char) * (strlen("empty") + 1));
		strcpy(buff, "empty");
		return buff;
	}
	buff = (char*)malloc(sizeof(char) * (strlen(current->token)+1));

	strcpy(buff, current->token);
	queue_head = queue_head->next;
	free(current->token);
	free(current);
	--myStrtok_count;

	return buff;
}

int queue_empty()
{
	if(queue_head == NULL)
		return 1;
	
	return 0;
}

void token_insert(char *str)
{
	token_queue *current;
	token_queue *input = (token_queue*)malloc(sizeof(token_queue));
	input->token = (char*)malloc(sizeof(char) * (strlen(str)+1));
	strcpy(input->token, str);
	input->next = NULL;

	if(queue_head == NULL)//queue is empty
	{
		queue_head = input;
	}
	else
	{
		current = queue_head;
		while(current->next != NULL)
			current = current->next;

		current->next = input;
	}
}

void free_myStrtok()
{
	while(queue_head != NULL)
	{
		token_queue *del = queue_head;
		queue_head = queue_head->next;
		free(del->token);
		free(del);
	}
	myStrtok_count = -1;
}
