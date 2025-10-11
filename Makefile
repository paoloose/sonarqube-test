CC=gcc
TARGET=main
CFLAGS=-lm
SRC=main.c

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

clean:
	rm -rf $(TARGET)
