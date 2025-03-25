#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main (void)
{
  int fd = open("simple.txt",O_RDONLY);
  if (fd < 0)
{
perror("Error opening file");
exit(EXIT_FAILURE);
}  
printf(" file '%s' opened successfully with file descriptor :%d\n", "simple.txt ,fd);
  close(fd);
return 0;
}
