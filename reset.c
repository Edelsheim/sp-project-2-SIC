#include "reset.h"

int reset()
{
	size_t i = 0;
	size_t k = 0;

	for(i=0; i != dProc.MemoryCol; ++i)
		for(k=0; k != dProc.MemoryRow; ++k)
			dProc.Memory[i][k] = 0;

	return 0;
}
