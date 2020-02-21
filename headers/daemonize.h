#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void write_f(char *file, char *mode, char *str);

void skeleton_daemon();