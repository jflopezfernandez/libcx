
vpath %.c src

RM := rm -f

CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -Og -ggdb3 -L../
CPPFLAGS := -Iinclude -I../include -D_GNU_SOURCE
LDFLAGS := -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now,-L../,-rpath,../
LDLIBS := -lcx

SRCS := $(notdir $(wildcard src/*.c))
OBJS := $(patsubst %.c,%.o,$(SRCS))

TARGET := tests-runner

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.c
	$(COMPILE.c) -o $@ $<

.PHONY: check
check: $(TARGET)
	@./$(TARGET) horse house cat dog mouse

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
