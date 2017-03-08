#CC=arm-linux-gcc
#CC=/usr/local/arm/4.3.2/bin/arm-linux-gcc
CC=gcc
CFLAGS=-Wall -O2
TARGET=maintest
#HDFLAGS=-I./include
HDFLAGS=-I/usr/include/
LDFLAGS=-L./lib

main: $(TARGET)

$(TARGET): testsqlite3.o
	$(CC) -o $(TARGET) testsqlite3.o -lsqlite3

%.o: %.c
	$(CC) -c $< $(CLAGS)

clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f *.db

