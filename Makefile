CC=gcc
LD=g++
C_LD=gcc
C_FLAGS=-Wall -fpic -O2 -std=c99 -g -c
CC_FLAGS=-Wall -fpic -O2 -std=c++11 -g -c
C_LD_FLAGS=-shared -lcurl -lsqlite3
CC_LD_FLAGS=-lcurl -lsqlite3 -lfunctions
SOURCEDIR=./sources
HEADDIR=./headers
OBJ=./objects
C_OBJ=./c_objects
DESTDIR=./bin
NAME=dataloop
LIB_DIR=./lib
INSTALL_DIR=../run

all:
	$(CC) $(C_FLAGS) -I$(HEADDIR) $(SOURCEDIR)/*.c;
	mv ./*.o $(C_OBJ);
	$(CC) $(CC_FLAGS) -I$(HEADDIR) $(SOURCEDIR)/*.cc;
	mv ./*.o $(OBJ);
	$(C_LD) $(C_OBJ)/*.o -o $(LIB_DIR)/libfunctions.so $(C_LD_FLAGS);
	$(LD) $(OBJ)/*.o -L $(LIB_DIR) -o $(DESTDIR)/$(NAME) $(CC_LD_FLAGS);
clean:
	rm -fv $(OBJ)/*;
	rm -fv $(C_OBJ)/*;
	rm -fv $(LIB_DIR)/*;
dev:clean all

install:
	cp $(DESTDIR)/$(NAME) $(INSTALL_DIR);
