# === Configuration ===
CC = gcc
CFLAGS = -Wall -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lcunit
TARGET = main
SRC = main.c

# Select the interface: basic, console, or automated
INTERFACE ?= basic
UPPER_INTERFACE := $(shell echo $(INTERFACE) | tr a-z A-Z)

# Default target
all: $(TARGET)

# Compile the test runner
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -DINTERFACE_$(UPPER_INTERFACE) $(SRC) -o $(TARGET) $(LDFLAGS)

# Run the test
run: $(TARGET)
	./$(TARGET)

# === Debug Build and Run ===
debug: CFLAGS += -g -O0 -DDEBUG -fsanitize=address -fno-omit-fram-pointer
debug: LDFLAGS += -fsanitize=address
debug: $(TARGET)
	ASAN_OPTIONS=detect=1 ./$(TARGET)

# ===== Release Build =====
release: CFLAGS += -O2 
release: clean $(TARGET)

# Cleanup
clean:
	rm -f $(TARGET) CUnitAutomated-*.xml

.PHONY: all run clean debug

