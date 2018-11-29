CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -pedantic -fPIC
CPPFLAGS=-Imtl-parser/src -I/opt/cuda/include

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

clean-all: clean
	make clean -C mtl-parser

.PHONY: clean clean-all deps
