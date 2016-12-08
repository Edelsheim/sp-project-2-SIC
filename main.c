#include "main.h"

int main(void)
{
	int result = 0;
	char input[255];
	Init();
	// Initial default value

	while(1)
	{
		printf("sicsim> ");
		fgets(input, sizeof(input), stdin);
		input[strlen(input)-1] = '\0';
		// input string line
		
		if(strncmp(input, "quit", strlen(input)) == 0 ||
			strncmp(input, "q", strlen(input)) == 0)
			break;

		result = command_control(input);
		if(result)
			break;
	}
	FreeMemory();
	return 0;
}

void Init()
{
	defInit();
	// Initial default processing value in defInit.h and .c

	commandInit();
	// Initial hash table and etc value in sicsim_command.h and .c
}

void FreeMemory()
{
	defInit_free();
	// free dProc.Memory
	free_control();
	// free memory in sicsim_command.h and .c
}
