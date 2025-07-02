# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wextra -std=c11

# Diretório de build
BUILD_DIR = build

# Busca todos os arquivos .c recursivamente (exceto o diretório build, se existir)
SRCS := $(shell find . -name '*.c' ! -path './$(BUILD_DIR)/*')
# Gera os nomes dos objetos a partir dos fontes, colocando-os no diretório build
OBJS := $(patsubst ./%, $(BUILD_DIR)/%, $(SRCS:.c=.o))

# Regra padrão para compilar o projeto
all: $(BUILD_DIR) $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lm

# Regra para criar o diretório build, se não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Regra genérica para compilar qualquer .c em .o dentro do build
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -rf $(BUILD_DIR) $(TARGET)