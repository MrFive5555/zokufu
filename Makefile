# CC=g++ -std=c++11 -Wall -fdiagnostics-color=always
CC=g++ -std=c++11 -Wall -g -O0
D_BIULD=build
D_INCLUDE=include
D_SRC=src
F_INCLUDE=-isystem . -I $(D_INCLUDE)
COMPILE=$(CC) $(F_INCLUDE) -c
LINK=$(CC) $(F_LINK)
common= \
	$(D_BIULD)/util.o \
	$(D_BIULD)/storage.o

default:
	@echo "no target given!"

test:test.out
	
geneology:geneology.out

test.out: \
	$(common) \
	$(D_BIULD)/test.o
	$(CC) $^ -o $@

geneology.out: \
	$(common) \
	$(D_BIULD)/main.o
	$(CC) $^ -o $@

$(D_BIULD)/%.o: $(D_SRC)/%.cpp $(D_INCLUDE)/*.h
	mkdir -p $(D_BIULD)
	$(COMPILE) $< -o $@

clean:
	-rm -rf $(D_BIULD)/*