TARGET := sic_xe
CFLAGS := -Wall -lm
OBJECTS := main.c defInit.c help.c history.c dump.c edit.c fill.c reset.c opcode.c mnemonic.c sicsim_command.c
SubOBJECTS := myStrtok.c myVerify.c myHash.c
CC := gcc -o

$(TARGET):$(OBJECTS)
			$(CC) $(TARGET) $(OBJECTS) $(SubOBJECTS) $(CFLAGS)

clean :
	rm -rf $(TARGET)
