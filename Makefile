
vpath %.asm src
vpath %.c src

RM          := rm -f
RMDIR       := rm -rf

STANDARD    := -std=c17
DIAGNOSTICS := -Wall -Wextra -Wpedantic
DEBUG       := -Og -ggdb3
ANALYZER    := -fanalyzer -Wanalyzer-too-complex
SANITIZER   := -fsanitize=address,leak,undefined
#PROFILING   := -pg -fprofile-arcs --coverage

CC          := gcc
CFLAGS      := $(STANDARD) $(DIAGNOSTICS) $(DEBUG) $(ANALYZER) $(SANITIZER) $(PROFILING)
CPPFLAGS    := -Iinclude -D_GNU_SOURCE
LDFLAGS     := -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now
LDLIBS      :=

SRCS        := $(notdir $(wildcard src/*.c))
OBJS        := $(patsubst %.c,%.o,$(SRCS))

TARGET      := libcx.so

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK.c) -shared -fPIC $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.c
	$(COMPILE.c) -fPIC -o $@ $<

PHONY: check
check: $(TARGET)
	$(MAKE) -C tests/ check

.PHONY: install
install: $(TARGET)
	@echo This feature has not yet been implemented.

.PHONY: uninstall
uninstall:
	@echo This feature has not yet been implemented.

.PHONY: help
help:
	@echo This feature has not yet been implemented.

.PHONY: docs
docs:
	doxygen docs/Doxyfile

.PHONY: clean
clean: clean-profiling-data
	$(RM) $(OBJS) $(TARGET)
	$(MAKE) -C tests/ clean

.PHONY: clean-profiling-data
clean-profiling-data:
	$(RM) ./*.{gcda,gcno,gcov,out} ./vgcore.*

.PHONY: clean-tags
clean-tags:
	$(RM) GPATH GRTAGS GTAGS

.PHONY: clean-docs
clean-docs:
	$(RMDIR) docs/{html,latex,man,perlmod}/

.PHONY: distclean
distclean: clean clean-tags clean-docs
	$(MAKE) -C tests/ distclean
