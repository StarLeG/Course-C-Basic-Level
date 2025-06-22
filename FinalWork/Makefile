CC = gcc
CFLAGS = -g -Wall -Wextra -std=gnu99 -O2  

TARGET = Temperature_Statistics
SOURCES = main.c \
		  climate_data.c \
		  readFileToBuffer.c\
		  menu.c
HEADERS = climate_data.h \
		  readFileToBuffer.h\
		  menu.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) 

clean:
	rm -f $(TARGET) *.o
	rm -f $(TARGET)
	rm -f $(TARGET) *.exe 

.PHONY: all clean

rebuild: clean all