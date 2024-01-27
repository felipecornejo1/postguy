CC = clang
CFlags = -g -Wall

SRC = src/main.c  # Specify the .c extension

BIN = bin/main

all: $(BIN)

$(BIN): $(SRC)  # Specific rule for building bin/main
	mkdir -p $(dir $(BIN))
	$(CC) $(CFlags) $< -o $@ -lcurl

clean:
	$(RM) -rf $(BIN) *.dSYM
