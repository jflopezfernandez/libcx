
vpath %.c src

#BUILD_TYPE  := Debug

RM          := rm -f

ifeq ($(BUILD_TYPE),Debug)
STANDARD    := -std=c17
DIAGNOSTICS := -Wall -Wextra -Wpedantic
OPTIMIZATION:= -Og
DEBUG       := -ggdb3
ANALYZER    := -fanalyzer -Wanalyzer-too-complex
SANITIZER   := -fsanitize=address,leak,undefined
PROFILING   := -pg -fprofile-arcs --coverage
else
STANDARD    := -std=c17
DIAGNOSTICS := -Wall -Wextra -Wpedantic
OPTIMIZATION:= -O3 -march=native
DEBUG       := -ggdb3
ANALYZER    := -fanalyzer
endif

CC          := gcc
CFLAGS      := $(STANDARD) $(DIAGNOSTICS) $(OPTIMIZATION) $(DEBUG) $(ANALYZER) $(SANITIZER) #$(PROFILING)
CPPFLAGS    := -Iinclude -I../include -D_GNU_SOURCE
LDFLAGS     := -L../ -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now,-L../,-rpath,../
LDLIBS      := -lcx -lcheck

SRCS        := $(notdir $(wildcard src/*.c))
OBJS        := $(patsubst %.c,%.o,$(SRCS))

TARGET      := tests-runner

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.c
	$(COMPILE.c) -o $@ $<

.PHONY: check
check: $(TARGET)
	@./$(TARGET) horse house cat dog mouse

.PHONY: clean
clean: clean-profiling-data
	$(RM) $(OBJS) $(TARGET)

.PHONY: clean-profiling-data
clean-profiling-data:
	$(RM) ./*.{gcda,gcno,gcov,out} ./callgrind.out.*

.PHONY: distclean
distclean: clean clean-profiling-data
