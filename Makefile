NAME				=	microsun_time
SYS_INI_DIR				=	/etc/php/7.4/cli/conf.d
SYS_EXTENSION_DIR		=	$(shell php-config --extension-dir)
HEADDIR				=	../../headers
EXTENSIONDIR		=	../../lib/php
LIBDIR				=	../../lib/shared
STATIC				=	../../lib/static
EXTENSION 			=	${NAME}.so
LOCAL	 			=	lib${NAME}.so
INIDIR				=	../../config
INI 				=	microsun.ini
COMPILER			=	g++
LINKER				=	g++
COMPILER_FLAGS		=	-Wall -c -O2 -std=c++11 -fpic -I${HEADDIR} -o
LINKER_FLAGS		=	-shared
LINKER_DEPENDENCIES	=	-lphpcpp
RM					=	rm -f
CP					=	cp -f
MKDIR				=	mkdir -p
SOURCES				=	$(wildcard *.cc)
OBJECTS				=	$(SOURCES:%.cc=%.o)
LOCAL_OBJECTS		=	./operators.o ./time_functions.o ./constructors.o ./functions.o
OBJ					=	./objects
AR					=	ar
ARFLAGS				=	rvs
STATLIB				=	lib${NAME}.a

all:					${OBJECTS} ${LOCAL} ${EXTENSION}

${EXTENSION}:			${OBJECTS}
						${LINKER} ${LINKER_FLAGS} -L${LIBDIR} -L${STATIC} -o ${EXTENSIONDIR}/$@ ${OBJECTS} ${LINKER_DEPENDENCIES}
						mv ./*.o ${OBJ}

${OBJECTS}:
						${COMPILER} ${COMPILER_FLAGS} $@ ${@:%.o=%.cc}
		
${LOCAL}:				${OBJECTS}
						${LINKER} ${LINKER_FLAGS} -o ${LIBDIR}/${LOCAL} ${LOCAL_OBJECTS} ${LINKER_DEPENDENCIES}
						${AR} ${ARFLAGS} ${STATIC}/${STATLIB} ${LOCAL_OBJECTS}

install:		
						rm -fv ${SYS_EXTENSION_DIR}/${EXTENSION};
						${CP} ${EXTENSIONDIR}/${EXTENSION} ${SYS_EXTENSION_DIR}
						${CP} ${INIDIR}/${INI} ${SYS_INI_DIR}
				
clean:
						${RM} ${EXTENSION} ${OBJECTS}

