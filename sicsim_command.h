#ifndef __SICSIM__
#define __SICSIM__

#include "defInit.h"
#include "myStrtok.h"

#include "help.h"
#include "history.h"
#include "dump.h"
#include "edit.h"
#include "fill.h"
#include "reset.h"
#include "opcode.h"
#include "mnemonic.h"

void commandInit();

int command_control(char *str);
int command_analyze(char *str);
int command_run();

void free_control();

#endif
