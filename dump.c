#include "dump.h"

int last = 0;// save next dump

int default_dump();// dump 10 lines
int dump_start(int start);// dump start to 10 lines
int dump_two(int start, int end);// dump start to end
int dump_full();// debug, dump full memory

int dump_print(int start, int end);// print

int dump(char *start, char *end)
{
	int hex_start=0, hex_end=0;

	check_empty(start)==1?
		hex_start = -1 : (hex_start = string_to_hex(start));

	check_empty(end)==1?
		hex_end = -1 : (hex_end = string_to_hex(end));
	
	if(hex_start == -1 && hex_end == -1)
		default_dump();// print 10 line
	else if(hex_start >= 0 && hex_end == -1)
		dump_start(hex_start);// dump start to 10 line
	else
		dump_two(hex_start, hex_end);// dump start to end
	
	return 0;
}

int default_dump()
{
	int start = last;
	int end = last + (0x10 * 10)-1;
	int result = 0;
	result = dump_print(start, end);

//	last = end+1;// stall next dump
	return result;
}

int dump_start(int start)
{
	int end = start + (0x10 * 10)-1;
	int result = 0;

	if((start % 0x10) > 0)
		end -= 0x10;

	result = dump_print(start, end);
//	last = end + 1;
	return result;
}

int dump_two(int start, int end)
{
	int result = 0;
	dump_print(start, end);
//	last = end+1;
	return result;
}

int dump_full()
{
	int result = dump_print(0, dProc.MemorySize - 1);
	last = 0;
	return result;
}

int dump_print(int start, int end)
{
	size_t row = 0, col = 0;
	size_t end_row = 0, end_col = 0;

	size_t i = 0, j = 0;
	if(start >= dProc.MemorySize)
		return 1;
	if(end >= dProc.MemorySize)
		return 1;
	if(start >= end)
		return 1;
	
	if(start < 0)
		return 1;
	if(end < 0)
		return 1;

	// start dump print

	printf("Start %02X\n", start);
	printf("End %02X\n", end);

	if(start == 0)
	{
		row = 0; 
		col = 0;
	}
	else
	{
		col = start / 0x10;
		row = start % 0x10;
	}
	
	end_col = end / 0x10;
	end_row = end % 0x10;

	for(i=col; i <= end_col; ++i)
	{
		// print memory col
		printf("%05X | ", (int)i * 0x10);

		// print memory row
		for(j=0; j != 0x10; ++j)
		{
			if((col == (int)i) && (j < row))
			{
				// print blank
				printf("  ");
			}
			else if(((end_col) == (int)i) && (j > end_row))
			{
				// print blank
				printf("  ");
			}
			else
			{
				printf("%02X", dProc.Memory[i][j]);
			}
			printf(" ");
		}
		printf("; ");
		
		// print byte ASCII
		// ASCII limit 0x20 ~ 0x7E
		// another ASCII print '.'
		for(j = 0; j != 0x10; ++j)
		{
			if((col == ((int)i)) && (j < row))
			{
				// print memory row is blank
				// print '.'
				printf(".");
			}
			else if((end_col == (int)i) && (j > end_row))
			{
				// print memory row is blank
				// print '.'
				printf(".");
			}
			else if(dProc.Memory[i][j] >= dProc.ASCII_min && 
					dProc.Memory[i][j] <= dProc.ASCII_max)
			{
				printf("%c", (char)dProc.Memory[i][j]);
			}
			else
			{
				// another print '.'
				printf(".");
			}
		}
		printf("\n");
	}
	last = end+1;
	return 0;
}
