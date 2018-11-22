CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -pedantic -fPIC

ifdef DEBUG
	CXXFLAGS+=-g
endif

OBJS=$(addprefix src/, parser.o types.o)
BIN=main
LIB=libobjparser.so

$(LIB): $(OBJS)
	$(LINK.cc) -shared -o $(LIB) $^ $(LDLIBS)

$(BIN): $(OBJS) src/$(BIN).o
	$(LINK.cc) -o $@ $^ $(LDLIBS)

clean:
	$(RM) $(BIN) $(OBJS) src/$(BIN).o $(LIB)

.PHONY: clean
