CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -pedantic -fPIC

ifdef DEBUG
	CXXFLAGS+=-g
endif

OBJS=$(addprefix src/, parser.o types.o)
LDLIBS=-Lmtl-parser -lmtlparser
BIN=main
LIB=libobjparser.so

$(LIB): $(OBJS) deps
	$(LINK.cc) -shared -o $@ $< $(LDLIBS)

$(BIN): $(OBJS) src/$(BIN).o
	$(LINK.cc) -o $@ $^ $(LDLIBS)

deps:
	make -C mtl-parser

clean:
	$(RM) $(BIN) $(OBJS) src/$(BIN).o $(LIB)
	make clean -C mtl-parser

.PHONY: clean deps
