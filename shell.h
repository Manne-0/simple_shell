#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>

int main(int argc, char *argv[]);
void prompt(char **input, size_t *input_size);
void tokenize(char *command, char **args);
void exe(char *command, char *programName);
char *_getenv(const char *name);
extern char **environ;
char *_strchr(char *s, char c);
char *_strdup(const char *s);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);
int myprintf(char *str, size_t size, const char *format, ...);
char *path(const char *command);

#endif
