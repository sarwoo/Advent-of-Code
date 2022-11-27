CC=gcc

CFLAGS=-Wall -Werror

all:
	@echo "Usage: make <filename without extension> "

day_04: libs/md5.c day_04.c
	$(CC) $(CFLAGS) libs/md5.c day_04.c -o $@

clean:
	 rm -f day_?? main

