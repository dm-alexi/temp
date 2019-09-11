#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
    char *s;
    int i = 1;
    int fd = open("input.txt", 0);
    /*
    while (get_next_line(fd, &s) > 0)
        printf("%s\n", s);*/
    while (get_next_line(fd, &s) > 0)
    {
        printf("%2d: %s\n", i++, s);
    }
    return 0;
}
