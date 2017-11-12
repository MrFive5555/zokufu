# CC=g++ -std=c++11 -Wall -fdiagnostics-color=always
CC=g++ -std=c++11 -Wall -g
D_OUT=out
D_INCLUDE=include
F_INCLUDE=-isystem . -I $(D_INCLUDE)
# F_LINK=-L lib  -lboost_regex -lboost_graph
F_LINKD=-L lib/ -Wl,-rpath=lib/
F_LINKF=-lboost_regex -lboost_graph
COMPILE=$(CC) $(F_INCLUDE) -c
LINK=$(CC) $(F_LINK)
common=\
	$(D_OUT)/util.o \
	$(D_OUT)/storage.o

default:
	@echo "no target given!"

test:test.out
	
geneology:geneology.out

test.out: \
	$(common) \
	$(D_OUT)/test.o
	$(CC) $(F_LINKD) $^ $(F_LINKF) -o $@

# genealogy.out: \
# 	$(D_OUT)/util.o \
# 	$(D_OUT)/storage.o \
# 	$(D_OUT)/main.o
# 	$(CC) $^ $(F_LINK) -o $@

geneology.out: \
	$(common) \
	$(D_OUT)/main.o
	$(CC) $(F_LINKD) $^ $(F_LINKF) -o $@

$(D_OUT)/%.o: %.cpp *.h
	mkdir -p $(D_OUT)
	$(COMPILE) $< -o $@

clean:
	rm -rf $(D_OUT)