#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFSIZE 1024
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void _checker(char *file1, char *file2);
void read_err(char *file);
void write_err(char *file);
void close_err(int fd);
#endif
