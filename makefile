# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wextra -std=c11

# Busca todos os arquivos .c recursivamente (exceto o diretório build, se existir)
SRCS := $(shell find . -name '*.c' ! -path './build/*')
# Gera os nomes dos objetos a partir dos fontes
OBJS := $(SRCS:.c=.o)

# Regra padrão para compilar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lm

# Regra genérica para compilar qualquer .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)