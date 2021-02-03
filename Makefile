<<<<<<< HEAD
NAME=time.cc
HEADDIR=./headers/
LIBDIR=/usr/local/lib/
STATIC=/usr/local/lib/
CC=gcc
LD=gcc
C_FLAGS=-Wall -c -O2 -std=c++11 -fpic -I${HEADDIR}
LD_FLAGS=-shared -lstdc++ -shared-libgcc
SOURCEDIR=./sources/
OBJ=./objects/
AR=ar
ARFLAGS=rvs
BLDDIR=./lib/
SHELL=/bin/bash

all: sources link_static link_shared

sources:
	@printf "...........................................................................\n";
	@printf "Compiling time.cc\n";
	@printf "To install run 'make install' as root after this is done\n";
	@printf "...........................................................................\n";
	@printf "Compiling sources...";
	$(CC) $(C_FLAGS) $(SOURCEDIR)*
	mv ./*.o $(OBJ)
	@printf "Done!\n";

link_static:
	@printf "...........................................................................\n";
	@printf "Linking static library..."
	$(AR) $(ARFLAGS) $(BLDDIR)lib$(NAME).a $(OBJ)*
	@printf "Done!\n";

link_shared:
	@printf "...........................................................................\n";
	@printf "Linking shared library..."
	$(LD) $(LD_FLAGS) $(OBJ)* -o $(BLDDIR)lib$(NAME).so
	@printf "Done!\n";

install:		
	@printf "...........................................................................\n";
	@printf "Installing libraries under /usr/local/lib/...";
	@if [ "$$USER" != "root" ]; then \
		echo "Please run install as root! Aborting." >&2; \
		exit 1; \
	fi
	@ldconfig
	@printf "Done!\n";
	@printf "...........................................................................\n";
	@printf "Thank you for using Time.cc\n";
	@printf "Consider supporting us on https://gitlab.com/sexycoders\n";
	@printf "...........................................................................\n";
				
clean:
	${RM} ${EXTENSION} ${OBJECTS}

=======
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
>>>>>>> 420b5c6e5f545982ca0e21c8f7c42ddbe472e0ce
