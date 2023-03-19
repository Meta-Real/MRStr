CC = gcc
CFLAGS = -O3 -Wall -std=c99

SDIR = srcs
ODIR = objs
TDIR = tests

SRCS = $(shell find $(SDIR) -name "*.c")
OBJS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
TSTS = $(shell find $(TDIR) -name "*.c")
OUTS = $(patsubst $(TDIR)/%.c, $(TDIR)/%.exe, $(TSTS))

LIB = libmrstr.a

make: $(LIB)

remake: clean $(LIB)

all: clean $(LIB) test

test: $(LIB) $(OUTS)
	for test in $(OUTS) ; do $$test ; done

$(LIB): $(OBJS)
	ar -r $(LIB) $(OBJS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TDIR)/%.exe: $(TDIR)/%.c
	$(CC) $(CFLAGS) $< $(LIB) -o $@ -lcriterion

clean:
	@rm -f $(shell find $(ODIR) -name "*.o")
	@rm -f $(LIB)

.PHONY: make remake all test clean
