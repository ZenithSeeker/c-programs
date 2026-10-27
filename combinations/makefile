CC = gcc
CFLAGS = -std=gnu99 -Wall -Wextra -Wvla
TARGET = counting


BUILDDIR = build
SRCDIR = src
LIBS = lib

SRCFILES := $(wildcard ${SRCDIR}/*.c)
OBJFILES := $(patsubst ${SRCDIR}/%.c, ${BUILDDIR}/%.o, ${SRCFILES})


all: ${TARGET}



${BUILDDIR}/%.o: ${SRCDIR}/%.c | ${BUILDDIR} 
	${CC} ${CFLAGS} -I${LIBS}  $< -c -o $@

${BUILDDIR}:
	mkdir $@

${TARGET}: ${OBJFILES} 
	${CC} $^ -o $@ -lm




.PHONY: clean
clean:
	rm -rf ${BUILDDIR}
	rm -f ${TARGET}
