TOP := $(shell pwd)
ARCH := $(shell getconf LONG_BIT)
UNAME_S := $(shell uname -s)
MKDIR_P := $(shell mkdir -p build)
MKDIR_TEST := $(shell mkdir -p build/test)

IDIR=include
CC=g++
CPP_FLAGS=-g -I. -W -Wall -pedantic -std=c++11 -O0

BUILD_DIR=build
LDIR=lib

_DEPS = web_client.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = web_client.o
OBJ = $(patsubst %,$(BUILD_DIR)/%,$(_OBJ))

LDLIBS = -lssl

# Chilkat.
# ifeq ($(UNAME_S),Linux)
#    INC += -Ilib/chilkat-9.5.0-x86_64-linux-gcc/include
#    LDLIBS += $(LDIR)/chilkat-9.5.0-x86_64-linux-gcc/lib/libchilkat-9.5.0.a -pthread
# else ifeq ($(UNAME_S),Darwin)
#    INC += -Ilib/chilkat-9.5.0-macosx-cpp11/include
#    LDLIBS += $(LDIR)/chilkat-9.5.0-macosx-cpp11/libStatic/libchilkat_x86_64.a
# endif

$(BUILD_DIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPP_FLAGS) -I$(IDIR) # $(INC)

$(BUILD_DIR)/client: build/main.o $(OBJ)
	$(CC) -o $@ $^ $(CPP_FLAGS) $(LDLIBS) 

# $(BUILD_DIR)/thread_test: build/thread_test.o $(OBJ)
# 	$(CC) -o $@ $^ $(LDLIBS) $(CPP_FLAGS) $(GOOGLE_PROFILER)

# Tests.

# _TESTS = url_database_test url_priority_list_test scheduler_test
# TESTS = $(patsubst %,$(BUILD_DIR)/test/%,$(_TESTS))
# 
# $(BUILD_DIR)/test/%.o: test/%.cpp $(DEPS)
# 	$(CC) -c -o $@ $< $(CPP_FLAGS) -I$(IDIR) $(INC)
# 
# $(BUILD_DIR)/test/%: $(BUILD_DIR)/test/%.o $(OBJ)
# 	$(CC) -o $@ $^ $(LDLIBS) $(CPP_FLAGS)
# 
# all: $(BUILD_DIR)/crawler $(BUILD_DIR)/thread_test $(TESTS)

# .PHONY: test
# 
# test:
# 	@for i in $(TESTS); do \
#           $$i; \
#           if [ $$? -eq 0 ]; then \
#             echo "$$i (PASSED)"; else echo "$$i (FAILED)"; fi; \
#         done;               

# Tasks.

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
