CC = gcc
CFLAGS = -Wall -Wextra -Wcast-qual -Wwrite-strings -ansi -pedantic -I .
OBJDIR = obj/Debug
TARGET = $(OBJDIR)/ooswsys_light_core.exe
SOURCES = app/main.c core/src/object_.c app/src/object_a1.c app/src/object_b1.c
HEADERS = core/inc/object_.h app/inc/object_a1.h app/inc/object_b1.h

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)
