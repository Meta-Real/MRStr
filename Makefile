CC := gcc
CFLAGS := -O3 -Wall -std=c99 -Wno-parentheses

SDIR := srcs
ODIR := objs
TDIR := tests

SRCS := $(shell find $(SDIR) -name "*.c")
OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
TSTS := $(shell find $(TDIR) -name "*.c")
OUTS := $(patsubst $(TDIR)/%.c, $(TDIR)/%.exe, $(TSTS))

LIB := libmrstr.a
DLL := mrstr.so

make: $(LIB) $(DLL)

remake: clean $(LIB) $(DLL)

all: clean-all $(LIB) $(DLL) test

test: $(DLL) $(OUTS)
	-@for test in $(OUTS) ; do $$test ; done

retest: clean-test $(DLL) $(OUTS)
	-@for test in $(OUTS) ; do $$test ; done

$(LIB): $(OBJS)
	ar -r $(LIB) $(OBJS)

$(DLL): $(OBJS)
	$(CC) -shared -o $(DLL) $(OBJS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -fPIC -o $@ $< -I .

$(TDIR)/%.exe: $(TDIR)/%.c
	$(CC) $(CFLAGS) $< $(DLL) -o $@ -I .

clean:
	@rm -f $(shell find $(ODIR) -name "*.o")
	@rm -f $(LIB) $(DLL)

clean-all: clean clean-test

clean-test:
	@rm -f $(shell find $(TDIR) -name "*.exe")

.PHONY: make remake all test retest clean clean-test
