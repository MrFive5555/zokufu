# CC=g++ -std=c++11 -Wall -fdiagnostics-color=always
CC=g++ -std=c++11 -Wall -g
D_BIULD=build
D_INCLUDE=include
D_SRC=src
F_INCLUDE=-isystem . -I $(D_INCLUDE)
# F_LINK=-L lib  -lboost_regex -lboost_graph
F_LINKD=-L lib/ -Wl,-rpath=lib/
F_LINKF=-lboost_regex -lboost_graph
COMPILE=$(CC) $(F_INCLUDE) -c
LINK=$(CC) $(F_LINK)
common=\
	$(D_BIULD)/util.o \
	$(D_BIULD)/storage.o

default:
	@echo "no target given!"

test:test.out
	
geneology:geneology.out

test.out: \
	$(common) \
	$(D_BIULD)/test.o
	$(CC) $(F_LINKD) $^ $(F_LINKF) -o $@

geneology.out: \
	$(common) \
	$(D_BIULD)/main.o
	$(CC) $(F_LINKD) $^ $(F_LINKF) -o $@

$(D_BIULD)/%.o: $(D_SRC)/%.cpp $(D_INCLUDE)/*.h
	mkdir -p $(D_BIULD)
	$(COMPILE) $< -o $@

clean:
	-rm -rf $(D_BIULD)/*