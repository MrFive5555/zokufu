# CC=g++ -std=c++11 -Wall -fdiagnostics-color=always
CC=g++ -std=c++11 -Wall
D_OUT=./out
F_INCLUDE=-isystem .
COMPILE=$(CC) $(F_INCLUDE) -c
LINK=$(CC)

default:
	@echo "no target given!"

test:test.out
	
genealogy:genealogy.out

test.out: \
	$(D_OUT)/test.o \
	$(D_OUT)/util.o \
	$(D_OUT)/storage.o
	$(LINK) $^ -o $@

genealogy.out: \
	$(D_OUT)/main.o \
	$(D_OUT)/util.o \
	$(D_OUT)/storage.o
	$(LINK) $^ -o $@

$(D_OUT)/%.o: %.cpp *.h
	mkdir -p $(D_OUT)
	$(COMPILE) $< -o $@

clean:
	rm -rf $(D_OUT)