#ifndef __mySTRTOK__
#define __mySTRTOK__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myStrtok(char *str);
char* myStrtok_pop();
int myStrtok_count;
void free_myStrtok();
#endif
