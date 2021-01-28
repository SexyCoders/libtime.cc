CC=gcc
LD=g++ -shared
CC_FLAGS=-Wall -fpic -O2 -std=c++11 -g -c
CC_LD_FLAGS=
SOURCEDIR=./sources
HEADDIR=./headers
OBJ=./objects
TESTDIR=./
NAME=libtimecc.so
LIB_DIR=./lib

all:
	$(CC) $(CC_FLAGS) -I$(HEADDIR) $(SOURCEDIR)/*.cc;
	mv ./*.o $(OBJ);
	$(LD) $(OBJ)/*.o -o $(LIB_DIR)/$(NAME) $(CC_LD_FLAGS);
	g++ ./main.cc -I./headers -L $(LIB_DIR) -o $(TESTDIR)/test $(CC_LD_FLAGS) -ltimecc;
clean:
	rm -fv $(OBJ)/*;
	rm -fv $(LIB_DIR)/*;
dev:clean all
