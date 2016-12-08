#include "fill.h"

int fill(char *start, char *end, char *value)
{
	int hex_start = 0, hex_end = 0, hex_value = 0;
	size_t start_col = 0, start_row = 0;
	size_t end_col = 0, end_row = 0;
	size_t i = 0, j = 0;

	// Verify, 1 is false
	if(check_empty(start))
		return 1;
	if(check_empty(end))
		return 1;
	if(check_empty(value))
		return 1;

	hex_start = string_to_hex(start);
	hex_end = string_to_hex(end);
	hex_value = string_to_hex(value);
	if(hex_start < 0 || hex_start >= dProc.MemorySize)
		return 1;
	if(hex_end < 0 || hex_end >= dProc.MemorySize)
		return 1;
	if(hex_value < 0 || hex_value > dProc.hexByte_max)
		return 1;
	if(hex_start >= hex_end)
		return 1;

	start_col = hex_start / 0x10;
	start_row = hex_start % 0x10;

	end_col = hex_end / 0x10;
	end_row = hex_end % 0x10;

	for(i=start_col; i <= end_col; ++i)
	{
		for(j=start_row; j != 0x10; ++j)
		{
			if((i == end_col) && (j > end_row))
				break;
			dProc.Memory[i][j] = hex_value;
		}
	}
	return 0;
}
