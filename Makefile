# Compiler and flags
CC := clang
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
	
check: $(TARGET)
	leaks -atExit -- ./build/a.out

# Clean
clean:
	rm -rf $(BUILDDIR)

.PHONY: run clean
