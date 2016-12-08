#include "history.h"

struct _history
{
	char *history;
	struct _history *next;
};

typedef struct _history sic_history;

sic_history *head = NULL;

int history()
{
	sic_history *print = head;
	while(print != NULL)
	{
		printf("%s\n", print->history);
		print = print->next;
	}
	return 0;
}

int history_input(char *str)
{
	sic_history *current;
	sic_history *input = (sic_history*)malloc(sizeof(sic_history));
	input->history = (char*)malloc(sizeof(char) * (strlen(str)+1));
	memcpy(input->history, str, sizeof(char) * strlen(str));
	input->next = NULL;

	if(head == NULL)//first input
	{
		head = input;
	}
	else// not first
	{
		current = head;
		while(current->next != NULL)
			current = current->next;

		current->next = input;
	}

	return 0;
}

void free_history()
{
	while(head != NULL)
	{
		sic_history *del = head;
		head = head->next;
		free(del->history);
		free(del);
	}
}
