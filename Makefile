# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Iinclude

# Directories
SRCDIR := src
INCDIR := include
BUILDDIR := build

# Source files
SRC := $(wildcard $(SRCDIR)/*.c $(SRCDIR)/*/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC))

# Targets
TARGET := $(BUILDDIR)/a.out

# Main target
$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $^ -o $@

# Object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean
clean:
	rm -rf $(BUILDDIR)

.PHONY: run clean
