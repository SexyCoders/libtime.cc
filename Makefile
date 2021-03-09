NAME=libtime.cc
HEADDIR=./headers/
LIBDIR=/usr/local/lib/
STATIC=/usr/local/lib/
INCLUDE_DIR=/usr/local/include/
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
PROFILE_D=/etc/profile.d/
INCLUDE_PATH=/usr/local/include/libtime.cc
SCRIPT_NAME=libtime.cc.sh

all: sources link_static link_shared install_instructions

sources:
	@echo "##########################################################";
	@echo "Building libtime.cc library";
	@echo "##########################################################";
	@if [ -f $(OBJDIR).lock ]; then \
		echo "Removing objects from previous build"; \
		rm -f $(OBJDIR)*; \
		rm -f $(OBJDIR).lock; \
	fi
	@echo "##########################################################";
	@printf "Compiling time.cc\n";
	@printf "To install run 'make install' and source the profile after this is done\n";
	@echo "##########################################################";
	@printf "Compiling time.cc\n";
	@printf "Compiling sources...\n";
	$(CC) $(C_FLAGS) $(SOURCEDIR)*
	mv ./*.o $(OBJ)
	@printf "Done!\n";

link_static:
	@echo "##########################################################";
	@printf "Compiling time.cc\n";
	@printf "Linking static library...\n"
	$(AR) $(ARFLAGS) $(BLDDIR)$(NAME).a $(OBJ)*
	@printf "Done!\n";

link_shared:
	@echo "##########################################################";
	@printf "Compiling time.cc\n";
	@printf "Linking shared library...\n"
	$(LD) $(LD_FLAGS) $(OBJ)* -o $(BLDDIR)$(NAME).so
	@printf "Done!\n";

install_instructions:
	@echo "##########################################################";
	@echo "Building lib DONE!";
	@echo "Shared and static libs located under lib directory.";
	@echo "To install system-wide use 'make install' as root";
	@echo "##########################################################";

install:		
	@echo "##########################################################";
	@printf "Installing libraries and headers under /usr/local/...\n";
	@if [ "$$USER" != "root" ]; then \
		echo "Please run install as root! Aborting." >&2; \
		exit 1; \
	fi
	@cp -v $(BLDDIR)$(NAME).so $(LIBDIR);
	@cp -v $(BLDDIR)$(NAME).a $(STATIC);
	@mkdir -p $(INCLUDE_DIR)$(NAME);
	@cp -v $(HEADDIR)* $(INCLUDE_DIR)$(NAME);
	echo "Setting variables...";
	@echo "#!/bin/bash" > $(PROFILE_D)$(SCRIPT_NAME);
	@echo "export CPATH=\"/usr/local/include/libtime.cc:\$$CPATH\";" >> $(PROFILE_D)$(SCRIPT_NAME);
	@echo "##########################################################";
	@echo "libauth.js install successful!";
	@echo "PLEASE SOURCE THE PROFILE OR REBOOT BEFORE USING!";
	@echo "##########################################################";
	@printf "Thank you for using Time.cc\n";
	@printf "Consider supporting us on https://gitlab.com/sexycoders\n";
	@echo "##########################################################";
				
clean:
	@rm -rfv $(INCLUDE_DIR)$(NAME);
	@rm -rfv $(LIBDIR)$(NAME).a;
	@rm -rfv $(LIBDIR)$(NAME).so;
	@rm -rfv $(PROFILE_D)$(SCRIPT_NAME);
