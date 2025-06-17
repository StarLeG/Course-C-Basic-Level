
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

TARGET = temp_app
SOURCES = main.c temp_api.c
HEADERS = temp_api.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: all clean