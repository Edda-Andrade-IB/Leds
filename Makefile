# Nombre del ejecutable
TARGET = test_leds

# Archivos fuente
SRCS = test/test_leds.c src/leds.c lib/Unity/src/unity.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc

# Flags del compilador
CFLAGS = -Wall -Wextra -g -fdiagnostics-color=always -I./lib/Unity/src -I./src

# Flags del linker
LDFLAGS = 

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Regla para ejecutar los tests
test: $(TARGET)
	./$(TARGET)

.PHONY: all clean test
