#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

// get_next_line.c
char* get_next_line(int fd);

#endif