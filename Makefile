
vpath %.asm src
vpath %.c src

export BUILD_TYPE  := Release

RM          := rm -f
RMDIR       := rm -rf

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
CPPFLAGS    := -Iinclude -D_GNU_SOURCE
LDFLAGS     := -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now
LDLIBS      :=

MAN3        := $(notdir $(wildcard docs/man/man3/*.3))
HDRS        := $(notdir $(wildcard include/*.h))
SRCS        := $(notdir $(wildcard src/*.c))
OBJS        := $(patsubst %.c,%.o,$(SRCS))

TARGET      := libcx.so

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK.c) -shared -fPIC $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.c
	$(COMPILE.c) -fPIC -o $@ $<

.PHONY: tests
tests: $(TARGET)
	$(MAKE) -C tests/

PHONY: check
check: $(TARGET)
	$(MAKE) -C tests/ check

.PHONY: install
install: $(TARGET)
	install --owner=root --group=root --mode=u+rwx,g+rx,g-w,o+rx,o-w -T $(TARGET) /usr/lib/$(TARGET)
	[ -d /usr/include/libcx/ ] || mkdir /usr/include/libcx/
	$(foreach HEADER,$(HDRS),install --owner=root --group=root --mode=u+rw,u-x,g+r,g-wx,o+r,o-wx -T `pwd`/include/$(HEADER) /usr/include/libcx/$(HEADER);)
	$(foreach MANPAGE3,$(MAN3),install --owner=root --group=root --mode=u+rw,u-x,g+r,g-wx,o+r,o-wx -T `pwd`/docs/man/man3/$(MANPAGE3) /usr/share/man/man3/$(MANPAGE3);)

.PHONY: uninstall
uninstall:
	[ -e /usr/lib/$(TARGET) ] && rm -f /usr/lib/$(TARGET) || true
	[ -d /usr/include/libcx/ ] && rm -rf /usr/include/libcx || true
	$(foreach MANPAGE3,$(MAN3),[ -e /usr/share/man/man3/$(MANPAGE3) ] && rm -f /usr/share/man/man3/$(MANPAGE3) || true)

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
	$(RMDIR) docs/{html,latex,perlmod}/

.PHONY: distclean
distclean: clean clean-tags clean-docs
	$(MAKE) -C tests/ distclean
