#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt(char **input, size_t *input_size);
void execute(char *input, char *programName);
char *_getenv(const char *name);
void myprintf(char *buffer, const char *format, const char *arg);
char *path(const char *command);

#endif
