# Define the compiler and flags
CC = gcc
WINDRES = windres

INCLUDE_PATHS = C:/dev/thirdparty/raylib/include
LIB_PATHS = C:/dev/thirdparty/raylib/lib

CFLAGS = -Wall $(foreach d, $(INCLUDE_PATHS), -I$d)
LDFLAGS = $(foreach d, $(LIB_PATHS), -L$d) -lraylib -lm -lgdi32 -lwinmm -lkernel32

# Define the source and target
SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

TARGET = bin/planetguard

# Resource file
RESOURCE = res/resource.rc
RESOURCE_OBJ = $(OBJ_DIR)/resource.o

# Define the make rules
all: $(TARGET)

$(TARGET): $(OBJS) $(RESOURCE_OBJ)
	@if not exist bin (mkdir bin)
	$(CC) $(CFLAGS) $(OBJS) $(RESOURCE_OBJ) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist $(OBJ_DIR) (mkdir $(OBJ_DIR))
	$(CC) $(CFLAGS) -c $< -o $@

$(RESOURCE_OBJ): $(RESOURCE)
	@if not exist $(OBJ_DIR) (mkdir $(OBJ_DIR))
	$(WINDRES) $< -O coff -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
