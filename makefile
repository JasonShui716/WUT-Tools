PROGRAM := wut-tools
BIN := ./bin
SOURCES := HttpReq.cpp LoginReq.cpp ScoreTableReq.cpp TimeTableReq.cpp main.cpp
HTML := $(wildcard ./html/*.html) cookies.txt
OBJS    := $(patsubst %.cpp,%.o,$(SOURCES))
CXX      := g++
CFLAGS  := -g -Wl,-Bstatic -Wall
INCLUDE := -I ./libcurl/linux/include
LIB     := -L./libcurl/linux/lib/ -lcurl -Wl,-Bdynamic -lrt -lpthread
.PHONY: clean install
$(PROGRAM): $(OBJS)
	$(CXX) -o $@ $^ $(LIB)
%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS) $(INCLUDE)
clean:
	rm $(OBJS) $(PROGRAM) $(HTML) -f
	rm -rf $(BIN)
install: $(PROGRAM)
	cp $(PROGRAM) ./bin
	cp $(PROGRAM) /usr/bin

