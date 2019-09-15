#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    char *s;
    int i = 1, l;
    int fd = open("input.txt", 0);
    int fd1 = open("input1.txt", 0), fd2 = open("input2.txt", 0);
    /*
    while (get_next_line(fd, &s) > 0)
        printf("%s\n", s);*/
/*
    while ((l = get_next_line(fd, &s)) > 0 && i < 10)
    {
        printf("%2d\t%d: %s\n", i++, l, s);
		}*/
    
    printf("%s\n", get_next_line(fd, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd1, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd1, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd2, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd2, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd, &s) > 0 ? s : "no more data");
    printf("%s\n", get_next_line(fd, &s) > 0 ? s : "no more data");
	printf("%s\n", get_next_line(fd1, &s) > 0 ? s : "no more data");
	printf("%s\n", get_next_line(fd, &s) > 0 ? s : "no more data");
    return 0;
}
