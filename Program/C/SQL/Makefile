SRC_PROCESS=sqlite3.c Main.c
EXE_PROCESS=Main
CFLAGS=-Wall
LDFLAGS=-lpthread -ldl

all:
	gcc ${CFLAGS} ${SRC_PROCESS} -o ${EXE_PROCESS} $(LDFLAGS)

clean:
	rm -f ${EXE_PROCESS}
