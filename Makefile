CC=gcc

CFLAGS=-Wall -g

TARGET=Lab2

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
