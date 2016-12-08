#include "sicsim_command.h"

char command_list[19][13] = { "error", "hi", "h", "du", "e", "f", "reset", "opcodelist", "mnemoniclist", "opcode", "mnemonic", "assemble", "type", "symbol", "disassemble", "progaddr", "loader", "run", "bp"};
size_t command_number = 0;

void commandInit()
{
	if(make_opcode())
		printf("opcode make fail\n");
	if(make_mnemonic())
		printf("mnemonic make fail\n");
}

int command_control(char *str)
{
	int check = 1;
	char *buff;
	char *command;
	buff = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(buff, str);

	buff = allLower(buff);
	check = myStrtok(buff);
	if(check)
		return 0;
	// strtok and stall token
	
	command = myStrtok_pop();
	// call first command
	// require free this.

	check = command_analyze(command);
	free(command); // is free memory
	if(check)
		return 0;

	check = command_run();
	if(check)
		return 0;

	free_myStrtok();

	history_input(buff);
	free(buff);
	// free buff

	return 0;
}

int command_analyze(char *str)
{
	int check = 1;
	size_t i=0;
	for(i=0; i != 19; ++i)
	{
		if(!strncmp(str, command_list[i], strlen(command_list[i])))
		{
			check = 0;
			break;
		}
	}

	if(check)
		return 1;

	command_number = i;
	return check;
}

int command_run()
{
	char **options;
	int check = 0;

	switch(command_number)
	{
		case 0:
			check = 1;break;
		case 1:
			check = history();break;
		case 2:
			check = help();break;
		case 3:
			options = (char**)malloc(sizeof(char*)*2);
			options[0] = myStrtok_pop();
			options[1] = myStrtok_pop();
			check = dump(options[0], options[1]);
			free(options[1]);
			free(options[0]);
			free(options);
			break;
		case 4:
			options = (char**)malloc(sizeof(char*)*2);
			options[0] = myStrtok_pop();
			options[1] = myStrtok_pop();

			check = edit(options[0], options[1]);
			free(options[1]);
			free(options[0]);
			free(options);
			break;
		case 5:
			options = (char**)malloc(sizeof(char*)*3);
			options[0] = myStrtok_pop();
			options[1] = myStrtok_pop();
			options[2] = myStrtok_pop();

			check = fill(options[0], options[1], options[2]);
			free(options[2]);
			free(options[1]);
			free(options[0]);
			free(options);
			break;
		case 6:
			check = reset();break;
		case 9:
			options = (char**)malloc(sizeof(char*));
			options[0] = myStrtok_pop();
	
			check = opcode(options[0]);
			free(options[0]);
			free(options);
			break;
		case 10:
			options = (char**)malloc(sizeof(char*));
			options[0] = myStrtok_pop();

			check = mnemonic(options[0]);
			free(options[0]);
			free(options);
			break;
		case 7:
			check = opcodelist();break;
		case 8:
			check = mnemoniclist();break;
/*		case 11:
			check = assemble();break;
		case 12:
			check = type();break;
		case 13:
			check = symbol();break;
		case 14:
			check = disassemble();break;
		case 15:
			check = progaddr();break;
		case 16:
			check = loader();break;
		case 17:
			check = run();break;
		case 18:
			check = bp();break; */
		default:
			check = 1;break;
	}
	return check;
}

void free_control()
{
	free_myStrtok();
	free_opcode();
	free_mnemonic();
}
