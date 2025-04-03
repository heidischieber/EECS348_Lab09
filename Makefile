CC := g++
CFLAGS := -Wall

OBJS := main.o

matrix.exe: $(OBJS)
	$(CC) $(OBJS) -o matrix.exe

clean:
	rm -f $(OBJS) matrix.exe