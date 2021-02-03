NAME=time.cc
HEADDIR=./headers/
LIBDIR=/usr/local/lib/
STATIC=/usr/local/lib/
CC=gcc
LD=gcc
C_FLAGS=-Wall -c -O2 -std=c++11 -fpic -I$(HEADDIR)
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
	@printf "Compiling sources...\n";
	$(CC) $(C_FLAGS) $(SOURCEDIR)*
	mv ./*.o $(OBJ)
	@printf "Done!\n";

link_static:
	@printf "...........................................................................\n";
	@printf "Linking static library...\n"
	$(AR) $(ARFLAGS) $(BLDDIR)lib$(NAME).a $(OBJ)*
	@printf "Done!\n";

link_shared:
	@printf "...........................................................................\n";
	@printf "Linking shared library...\n"
	$(LD) $(LD_FLAGS) $(OBJ)* -o $(BLDDIR)lib$(NAME).so
	@printf "Done!\n";

install:		
	@printf "...........................................................................\n";
	@printf "Installing libraries under /usr/local/lib/...";
	@if [ "$$USER" != "root" ]; then \
		echo "Please run install as root! Aborting." >&2; \
		exit 1; \
	fi
	@ldconfig;
	@printf "Done!\n";
	@printf "...........................................................................\n";
	@printf "Thank you for using Time.cc\n";
	@printf "Consider supporting us on https://gitlab.com/sexycoders\n";
	@printf "...........................................................................\n";
				
clean:
	${RM} ${EXTENSION} ${OBJECTS}
