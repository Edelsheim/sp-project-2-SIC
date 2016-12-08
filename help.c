#include "help.h"

int help()
{
	printf("h[elp]\n");
	printf("q[uit]\n");
	printf("hi[story]\n");
	printf("du[mp] [start, end]\n");
	printf("e[dit] address, value\n");
	printf("f[ill] start, end, value\n");
	printf("reset\n");
	printf("opcode mnemonic\n");
	printf("mnemonic opcode\n");
	printf("opcodelist\n");
	printf("mnemoniclist\n");
	printf("assemble filename\n");
	printf("type filename\n");
	printf("symbol\n");
	printf("disassemble filename\n");
	printf("progaddr [address]\n");
	printf("loader [object filename][....]\n");
	printf("run\n");
	printf("bp\n");
	printf("bp [address]\n");
	printf("bp clear\n");
	return 0;
}
