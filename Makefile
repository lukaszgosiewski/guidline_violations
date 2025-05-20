CC = gcc
CFLAGS = -Wall
OBJS = main.o utils.o processor.o

# Default target
all: app

# Link the executable
app: $(OBJS)
	$(CC) $(CFLAGS) -o app $(OBJS)

# Compile main.c
main.o: main.c utils.h processor.h
	$(CC) $(CFLAGS) -c main.c

# Compile utils.c
utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

# Compile processor.c
processor.o: processor.c processor.h utils.h
	$(CC) $(CFLAGS) -c processor.c

# Clean up
clean:
	rm -f app $(OBJS)

# Run the application
run: app
	./app "Hello World"
