CC := gcc
CFLAGS := -O3 -Wall -std=c99 -Wno-parentheses

SDIR := srcs
PDIR := psrcs
ODIR := objs
TDIR := tests

SRCS := $(shell find $(SDIR) -name "*.c")
PRCS := $(shell find $(PDIR) -name "*.c")

OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
PBJS := $(patsubst $(PDIR)/%.c, $(ODIR)/%.o, $(PRCS))

TSTS := $(shell find $(TDIR) -name "*.c")
OUTS := $(patsubst $(TDIR)/%.c, $(TDIR)/%.exe, $(TSTS))

LIB := libmrstr.a
DLL := mrstr.so

make: $(LIB)

remake: clean $(LIB)

all: clean $(LIB) test

test: $(LIB) $(OUTS)
	-@for test in $(OUTS) ; do $$test ; done

retest: clean-test $(LIB) $(OUTS)
	-@for test in $(OUTS) ; do $$test ; done

$(LIB): $(OBJS) $(PBJS)
	ar -r $(LIB) $(OBJS) $(PBJS)
	$(CC) -shared -o $(DLL) $(OBJS) $(PBJS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -fPIC -o $@ $< -I .

$(ODIR)/%.o: $(PDIR)/%.c
	$(CC) $(CFLAGS) -c -fPIC -o $@ $< -I .

$(TDIR)/%.exe: $(TDIR)/%.c
	$(CC) $(CFLAGS) $< $(LIB) -o $@ -I .

clean: clean-test
	@rm -f $(shell find $(ODIR) -name "*.o")
	@rm -f $(LIB) $(DLL)

clean-test:
	@rm -f $(shell find $(TDIR) -name "*.exe")

.PHONY: make remake all test clean
