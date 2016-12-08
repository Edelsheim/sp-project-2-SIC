#include "edit.h"

int edit(char *address, char *value)
{
	int hex_address = 0, hex_value = 0;
	int col=0, row=0;
	if(check_empty(address))
		return 1;
	if(check_empty(value))
		return 1;

	hex_address = string_to_hex(address);
	hex_value = string_to_hex(value);
	col = hex_address / 0x10;
	row = hex_address % 0x10;

	dProc.Memory[col][row] = hex_value;
	return 0;
}
