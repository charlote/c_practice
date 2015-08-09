#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    char c; //copy one byte
    int r, in, out;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
    while(read(in, &c, 1) == 1){
        write(out, &c, 1);
    }
    close(in);
    close(out);
    printf("Copy Completion!\n");
    exit(0);
}
/*  diff -q A_file B_file   //compiler the file*/
