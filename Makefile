
vpath %.asm src
vpath %.c src

RM := rm -f

CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -Og -ggdb3
CPPFLAGS := -Iinclude -D_GNU_SOURCE
LDFLAGS := -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now
LDLIBS :=

SRCS := $(notdir $(wildcard src/*.c))
OBJS := $(patsubst %.c,%.o,$(SRCS))

TARGET := libcx.so

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK.c) -shared -fPIC $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.c
	$(COMPILE.c) -fPIC -o $@ $<

PHONY: check
check: $(TARGET)
	$(MAKE) -C tests/ check

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
