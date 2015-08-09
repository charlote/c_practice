#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    char c[10]; //copy 10 byte
    int r, in, out;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
    while((r = read(in, c, 10)) > 1){
        write(out, c, r);
    }
    close(in);
    close(out);
    printf("Copy Completion!\n");
    exit(0);
}
/*  diff -q A_file B_file   //compiler the file*/
