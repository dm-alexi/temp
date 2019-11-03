#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"
#include <float.h>
#include <fcntl.h>
#include <limits.h>

int main()
{
  ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
  ft_printf("%\n");
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%s\n", NULL);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%S", NULL);
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
  ft_printf("%C\n", 15000);

  int fd = open("try.txt", 1);

  ft_printf("%d\n", fd);

  ft_dprintf(fd, "\n");
  ft_dprintf(fd, "%%\n");
  ft_dprintf(fd, "%d\n", 42);
  ft_dprintf(fd, "%d%d\n", 42, 41);
  ft_dprintf(fd, "%d%d%d\n", 42, 43, 44);
  ft_dprintf(fd, "%ld\n", 2147483647);
  ft_dprintf(fd, "%lld\n", 9223372036854775807);
  ft_dprintf(fd, "%x\n", 505);
  ft_dprintf(fd, "%X\n", 505);
  ft_dprintf(fd, "%p\n", &ft_printf);
  ft_dprintf(fd, "%20.15d\n", 54321);
  ft_dprintf(fd, "%-10d\n", 3);
  ft_dprintf(fd, "% d\n", 3);
  ft_dprintf(fd, "%+d\n", 3);
  ft_dprintf(fd, "%010d\n", 1);
  ft_dprintf(fd, "%hhd\n", 0);
  ft_dprintf(fd, "%jd\n", 9223372036854775807);
  ft_dprintf(fd, "%zd\n", 4294967295);
  ft_dprintf(fd, "%\n");
  ft_dprintf(fd, "%u\n", 4294967295);
  ft_dprintf(fd, "%o\n", 40);
  ft_dprintf(fd, "%%#08x\n", 42);
  ft_dprintf(fd, "%x\n", 1000);
  ft_dprintf(fd, "%#X\n", 1000);
  ft_dprintf(fd, "%s\n", NULL);
  ft_dprintf(fd, "%S\n", L"ݗݜशব");
  ft_dprintf(fd, "%S", NULL);
  ft_dprintf(fd, "%s%s\n", "test", "test");
  ft_dprintf(fd, "%s%s%s\n", "test", "test", "test");
  ft_dprintf(fd, "%C\n", 15000);


 ft_printf("%e", 153487.89);
    return 0;
}
