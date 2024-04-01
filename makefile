CC=gcc
CFLAGS=-Wall -Werror
DEPS=c_frequency_map.h c_string_map.h
SRCS=main.c c_frequency_map.c c_string_map.c
OBJECTS=$(SRCS:.c=.o)
TARGET=cm

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	if exist *.o del *.o
	if exist $(TARGET).exe del $(TARGET).exe

