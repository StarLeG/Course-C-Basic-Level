
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

TARGET = Temperature_Statistics
SOURCES = main.c temp_api.c readFileToBuffer.c
HEADERS = temp_api.h readFileToBuffer.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: all clean