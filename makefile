TARGET = dirsize

# Compilador e flags
CC = gcc
CFLAGS = -Wall -g -O3

# Regra principal
all: $(TARGET)

$(TARGET): dirsize.c
	$(CC) $(CFLAGS) -o $(TARGET) dirsize.c

# Regra para limpar os arquivos compilados
clean:
	rm -f $(TARGET)
