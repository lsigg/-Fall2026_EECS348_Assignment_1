CC = gcc
CFLAGS = -Wall -Wextra -std=c11

BUILD_DIR = build
PROGRAMS = $(BUILD_DIR)/chatgptcode $(BUILD_DIR)/claudecode $(BUILD_DIR)/improvedclaudecode

.PHONY: all test clean

all: $(PROGRAMS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/chatgptcode: chatgptcode.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/claudecode: claudecode.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/improvedclaudecode: improvedclaudecode.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

test: all
	printf "7\n" | ./$(BUILD_DIR)/chatgptcode
	printf "7\n" | ./$(BUILD_DIR)/claudecode
	printf "7\n" | ./$(BUILD_DIR)/improvedclaudecode

clean:
	rm -rf $(BUILD_DIR)
