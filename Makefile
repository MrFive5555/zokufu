# CC=g++ -std=c++11 -Wall -fdiagnostics-color=always
CC=g++ -std=c++11 -Wall
D_OUT=./out
F_INCLUDE=-isystem .
F_LINK=-L lib  -lboost_regex -lboost_graph -lboost_regex -lboost_graph
COMPILE=$(CC) $(F_INCLUDE) -c
LINK=$(CC) $(F_LINK)

default:
	@echo "no target given!"

test:test.out
	
geneology:genealogy.out

test.out: \
	$(D_OUT)/util.o \
	$(D_OUT)/storage.o \
	$(D_OUT)/test.o
	$(LINK) $^ -o $@

genealogy.out: \
	$(D_OUT)/util.o \
	$(D_OUT)/storage.o \
	$(D_OUT)/main.o
	$(LINK) $^ -o $@

$(D_OUT)/%.o: %.cpp *.h
	mkdir -p $(D_OUT)
	$(COMPILE) $< -o $@

clean:
	rm -rf $(D_OUT)