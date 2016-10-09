### ---------------------------------------------------------------------------
### EXECUTABLES
### ---------------------------------------------------------------------------

CC = gcc
OBJDUMP = objdump

### ---------------------------------------------------------------------------
### FILES
### ---------------------------------------------------------------------------

SOURCES = $(wildcard *.c)
HEADERS = $(SOURCES:.c=.h)
OBJECTS = $(SOURCES:.c=.o)
LISTINGS = $(SOURCES:.c=.S)

OUTPUT = bin/dhpcemu

### ---------------------------------------------------------------------------
### PARAMETERS
### ---------------------------------------------------------------------------

STANDARD = -std=gnu11
WARNINGS = -Wall -Wstrict-prototypes
TUNNING = -O0 -fshort-enums
ERRORS = -Werror

FLAGS = $(STANDARD) $(WARNINGS) $(ERRORS) $(TUNNING)
GTKLIB=`pkg-config --cflags --libs gtk+-3.0`
LIBS = $(GTKLIB) -rdynamic -lm

### ---------------------------------------------------------------------------
### TARGETS
### ---------------------------------------------------------------------------

bin: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUT) $(LIBS)

asm: $(LISTINGS)

clean:
	-rm -f *.o *.lst *~ ./bin/*~ $(OUTPUT)

### ---------------------------------------------------------------------------
### RECIPES
### ---------------------------------------------------------------------------

%.o: %.c
	 $(CC) $(FLAGS) -c -g -o $@ $^ $(LIBS)

%.S: %.o
	$(OBJDUMP) -d -M intel -S $< > $@
	mv *.S asm
