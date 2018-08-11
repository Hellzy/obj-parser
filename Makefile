CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -pedantic

ifdef DEBUG
	CXXFLAGS+=-g
endif

OBJS=$(addprefix src/, parser.o)
BIN=main
LIB=libobjparser.so

$(BIN): $(OBJS) src/$(BIN).o
	$(LINK.cc) -o $@ $^ $(LDLIBS)

lib: $(OBJS)
	$(LINK.cc) -shared -o $(LIB) $^ $(LDLIBS)

clean:
	$(RM) $(BIN) $(OBJS) src/$(BIN).o $(LIB)

.PHONY: clean lib
