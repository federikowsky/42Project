# Definizione dei percorsi
SRC_DIR := src
BUILD_DIR := build
TEST_DIR := testing
# Estensioni dei file
SRC_EXT := cpp
# Nome dell'eseguibile
TARGET := webserver
# Compilatore e opzioni
CC := g++
CFLAGS := -std=c++98 -g -Wall -Wextra

# Trova tutti i file sorgente nella cartella src/ e testing/
SOURCES := $(wildcard $(SRC_DIR)/*.$(SRC_EXT)) $(wildcard $(TEST_DIR)/*.$(SRC_EXT))

# Genera i nomi dei file oggetto nella cartella build/
OBJECTS := $(patsubst $(SRC_DIR)/%.$(SRC_EXT),$(BUILD_DIR)/%.o,$(filter %,$(SOURCES)))

# Target predefinito
all: $(TARGET)

# Compila il target
$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

# Compila i file oggetto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compila i file oggetto per i file sorgente nella cartella testing/
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.$(SRC_EXT)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia dei file generati
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

re: clean all

# Fai in modo che il makefile non cerchi file con gli stessi nomi dei target
.PHONY: all clean

